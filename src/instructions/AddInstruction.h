#pragma once

#include "common/Utils.h"
#include "interfaces/IInstruction.h"

namespace lc3_vm::instructions {
/**
 * \class AddInstruction
 * \brief implementation of ADD instruction handler
 */
class AddInstruction : public interfaces::IInstruction
{
public:
    /**
     * \copydoc interfaces::IInstruction
     */
    inline void operator()(common::Types::instruction_t instruction) override
    {
        common::Types::regval_t r0 = (instruction >> 9) & 0x7;      // destination register
        common::Types::regval_t r1 = (instruction >> 6) & 0x7;      // first operand
        common::Types::regval_t immFlag = (instruction >> 5) & 0x1; // immediate mode

        if (immFlag) {
            common::Types::regval_t imm5 = common::Utils::signExtend(instruction & 0x1F, 5);
            // todo: write to REG[r0] = REG[r1] + imm5;
        } else {
            common::Types::regval_t r2 = instruction & 0x7;
            // todo: write to REG[r0] = REG[r1] + REG[r2]
        }

        // todo: update flag
    }

    ~AddInstruction() override = default;
};
}
