#pragma once

#include "common/Singleton.h"
#include "common/Utils.h"
#include "interfaces/IInstruction.h"
#include "sysmanagement/MemoryManager.h"
#include "sysmanagement/RegisterManager.h"

namespace lc3_vm::instructions {
/**
 * \class LdiInstruction
 * \implements interfaces::IInstruction
 * \brief implementation of LDI instruction handler
 */
class LdiInstruction : public interfaces::IInstruction
{
public:
    /**
     * \copydoc interfaces::IInstruction::operator()(common::Types::instruction_t)
     */
    void operator()(common::Types::instruction_t instruction) override
    {
        auto& memManager = common::Singleton<sysmanagement::MemoryManager>::get();
        auto& regManager = common::Singleton<sysmanagement::RegisterManager>::get();

        auto dr = (instruction >> 9) & 0x7;
        auto pcOffset = common::Utils::signExtend(instruction & 0x1FF, 9);
        auto currentPc = regManager.getVal(hardware::RegistersSet::R_PC);

        auto val = memManager.read(currentPc + pcOffset);

        if (!val) {
            throw std::runtime_error("[LdiInstruction]: Cannot read memory by indirect address: " +
                                     std::to_string(currentPc + pcOffset));
        }

        regManager.setVal(static_cast<hardware::RegistersSet>(dr), *val);

        regManager.updateRCond(static_cast<hardware::RegistersSet>(dr));
    }

    ~LdiInstruction() override = default;
};
}