#pragma once

#include "common/Singleton.h"
#include "interfaces/IInstruction.h"
#include "sysmanagement/RegisterManager.h"

namespace lc3_vm::instructions {
/**
 * \class BitwiseNotInstruction
 * \implements interfaces::IInstruction
 * \brief Bitwise not (~) instruction implementation
 */
class BitwiseNotInstruction : public interfaces::IInstruction
{
public:
    /**
     * \copydoc interfaces::IInstruction::operator()(common::Types::instruction_t)
     */
    inline void operator()(common::Types::instruction_t instruction) override
    {
        auto& regManager = common::Singleton<sysmanagement::RegisterManager>::get();

        std::uint16_t r0 = (instruction >> 9) & 0x7;
        std::uint16_t r1 = (instruction >> 6) & 0x7;

        regManager.setVal(static_cast<hardware::RegistersSet>(r0),
                          ~regManager.getVal(static_cast<hardware::RegistersSet>(r1)));
        regManager.updateRCond(static_cast<hardware::RegistersSet>(r0));
    }

    ~BitwiseNotInstruction() override = default;
};
}