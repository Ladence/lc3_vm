#pragma once

#include "common/Singleton.h"
#include "common/Utils.h"
#include "interfaces/IInstruction.h"
#include "sysmanagement/RegisterManager.h"

namespace lc3_vm::instructions {
/**
 * \class AddInstruction
 * \brief implementation of ADD instruction handler
 */
class AddInstruction : public interfaces::IInstruction
{
public:
    /**
     * \copydoc interfaces::IInstruction::operator()(common::Types::instruction_t)
     */
    inline void operator()(common::Types::instruction_t instruction) override
    {
        auto& regManager = common::Singleton<sysmanagement::RegisterManager>::get();

        common::Types::regval_t r0 = (instruction >> 9) & 0x7;      // destination register
        common::Types::regval_t r1 = (instruction >> 6) & 0x7;      // first operand
        common::Types::regval_t immFlag = (instruction >> 5) & 0x1; // immediate mode

        if (immFlag) {
            common::Types::regval_t imm5 = common::Utils::signExtend(instruction & 0x1F, 5);
            // reg[r0] = reg[r1] + imm5
            regManager.setVal(static_cast<hardware::RegistersSet>(r0),
                              regManager.getVal(static_cast<hardware::RegistersSet>(r1)) + imm5);
        } else {
            common::Types::regval_t r2 = instruction & 0x7;
            // reg[r0] = reg[r1] + reg[r2]
            regManager.setVal(static_cast<hardware::RegistersSet>(r0),
                              regManager.getVal(static_cast<hardware::RegistersSet>(r1)) +
                                  regManager.getVal(static_cast<hardware::RegistersSet>(r2)));
        }

        regManager.updateRCond(static_cast<hardware::RegistersSet>(r0));
    }

    ~AddInstruction() override = default;
};
}
