#pragma once

#include <cstddef>

#include "hardware/RegistersSet.h"
#include "common/Types.h"

namespace lc3_vm::interfaces {
    /**
     * \interface IRegisterManager
     * \brief interface describing register manager of the machine
     */
    class IRegisterManager {
    public:
        /**
         * \brief sets value of the register
         * \param reg register
         * \param val value to set
         */
        virtual void setVal(hardware::RegistersSet reg, common::Types::regval_t val) = 0;

        virtual ~IRegisterManager() = default;
    };
}
