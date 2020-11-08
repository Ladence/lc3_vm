#pragma once

#include "Types.h"

namespace lc3_vm::common {
    /**
     * \class Constants
     * \brief Utils class contains only public static constants
     */
    class Constants {
    public:
        static constexpr Types::regval_t START_POS = 0x3000; ///< Start position byte of Program Counter Register
        static constexpr std::uint16_t MEMORY_SIZE = UINT16_MAX; ///< Virtual Machine's memory size (according to spec)
    };
}