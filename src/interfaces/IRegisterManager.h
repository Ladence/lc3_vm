#pragma once

#include <cstddef>
#include <optional>

#include "common/Types.h"
#include "hardware/RegistersSet.h"

namespace lc3_vm::interfaces {
/**
 * \interface IRegisterManager
 * \brief interface describing register manager of the machine
 */
class IRegisterManager
{
public:
    /**
     * \brief sets value of the register
     * \param reg register
     * \param val value to set
     */
    virtual void setVal(hardware::RegistersSet reg, common::Types::regval_t val) = 0;

    /**
     * \brief gets value of the register
     * \param reg register
     * \return current value of the register. In case of error it returns std::nullopt
     */
    virtual std::optional<common::Types::regval_t> getVal(hardware::RegistersSet reg) = 0;

    virtual ~IRegisterManager() = default;
};
}
