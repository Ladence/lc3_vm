#pragma once

#include <unordered_map>

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
     */
    void setVal(hardware::RegistersSet reg, common::Types::regval_t val);

    /**
     * \copydoc interfaces::IRegisterManager::getVal()
     */
    std::optional<common::Types::regval_t> getVal(hardware::RegistersSet reg);

private:
    std::unordered_map<hardware::RegistersSet, common::Types::regval_t> m_registers;
};

}
