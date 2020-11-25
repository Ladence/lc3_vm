#pragma once

#include "common/Singleton.h"
#include "common/Utils.h"
#include "interfaces/IInstruction.h"
#include "sysmanagement/RegisterManager.h"

namespace lc3_vm::instructions {
/**
 * \class BranchInstruction
 * \implements interfaces::IInstruction
 * \brief Branch instruction implementation
 */
class BranchInstruction : public interfaces::IInstruction
{
public:
    /**
     * \copydoc interfaces::IInstruction::operator()(common::Types::instruction_t)
     */
    inline void operator()(common::Types::instruction_t instruction) override
    {
        auto& regManager = common::Singleton<sysmanagement::RegisterManager>::get();

        std::uint16_t pcOffset = common::Utils::signExtend(instruction & 0x1FF, 9);
        std::uint16_t condFlag = (instruction >> 9) & 0x7;

        if (condFlag & regManager.getVal(hardware::RegistersSet::R_COND)) {
            regManager.setVal(hardware::RegistersSet::R_PC, regManager.getVal(hardware::RegistersSet::R_PC) + pcOffset);
        }
    }

    ~BranchInstruction() override = default;
};
}