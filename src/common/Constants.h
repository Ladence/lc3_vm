#pragma once

#include "Types.h"

namespace lc3_vm::common {
    /**
     * \class Constants
     * \brief Utils class contains only public static constants
     */
    class Constants {
    public:
        static constexpr Types::regval_t START_POS = 0x3000;
    };
}