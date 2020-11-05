#pragma once

#include <cstdint>

namespace lc3_vm::hardware {
    /**
     * \enum RegistersSet
     * \brief this enum describes register set of LC3's virtual machine
     */
    enum class RegistersSet : std::uint8_t {
        R_R0 = 0, ///< general purpose R_R0
        R_R1, ///< general purpose R_R1
        R_R2, ///< general purpose R_R2
        R_R3, ///< general purpose R_R3
        R_R4, ///< general purpose R_R4
        R_R5, ///< general purpose R_R5
        R_R6, ///< general purpose R_R6
        R_R7, ///< general purpose R_R7
        R_PC, ///< program counter register
        R_COND, ///< conditional flag register
        R_COUNT ///< register count
    };
}