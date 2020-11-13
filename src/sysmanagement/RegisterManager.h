#pragma once

#include <array>

#include "common/Types.h"
#include "hardware/RegistersSet.h"

namespace lc3_vm::sysmanagement {
/**
 * \class RegisterManager
 * \implements interfaces::IRegisterManager
 */
class RegisterManager
{
public:
    /**
     * \brief Sets registers in initial state (0x0000)
     */
    RegisterManager();

    /**
     * \copydoc interfaces::IRegisterManager::setVal()
     * todo: fix doc
     */
    void setVal(hardware::RegistersSet reg, common::Types::regval_t val);

    /**
     * \copydoc interfaces::IRegisterManager::getVal()
     * todo: fix doc
     */
    lc3_vm::common::Types::regval_t getVal(hardware::RegistersSet reg);

    void updateRCond(hardware::RegistersSet reg) noexcept;

private:
    std::array<common::Types::regval_t, static_cast<std::uint8_t>(hardware::RegistersSet::R_COUNT)> m_registers;
};

}
