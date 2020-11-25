#pragma once

#include <common/Utils.h>

#include "common/Singleton.h"
#include "interfaces/IInstruction.h"
#include "sysmanagement/RegisterManager.h"

namespace lc3_vm {
/**
 * \class AndInstruction
 * \implements interfaces::IInstruction
 * \brief implementation of bitwise AND instruction
 */
class BitwiseAndInstruction : public interfaces::IInstruction
{
public:
    /**
     * \copydoc interfaces::IInstruction::operator()(common::Types::instruction_t)
     */
    void operator()(common::Types::instruction_t instruction) override
    {
        auto& regManager = common::Singleton<sysmanagement::RegisterManager>::get();
        auto r0 = (instruction >> 9) & 0x7;
        auto r1 = (instruction >> 6) & 0x7;
        auto immFlag = (instruction >> 5) & 0x1;

        if (immFlag) {
            auto imm5 = common::Utils::signExtend(instruction & 0x1F, 5);

            // reg[r0] = reg[r1] & imm5;
            regManager.setVal(static_cast<hardware::RegistersSet>(r0),
                              regManager.getVal(static_cast<hardware::RegistersSet>(r1)) & imm5);
        } else {
            auto r2 = instruction & 0x7;
            // reg[r0] = reg[r1] & reg[r2]
            regManager.setVal(static_cast<hardware::RegistersSet>(r0),
                              regManager.getVal(static_cast<hardware::RegistersSet>(r1)) &
                                  regManager.getVal(static_cast<hardware::RegistersSet>(r2)));
        }

        regManager.updateRCond(static_cast<hardware::RegistersSet>(r0));
    }

    ~BitwiseAndInstruction() override = default;
};
}