#pragma once

namespace lc3_vm::hardware {
    /**
     * \enum State
     * \brief this enum consists state of R_COND register (the only one condition flag of the LC3)
     */
    enum class ConditionFlagState {
        FL_POS = 1 << 0, ///< positive
        FL_ZRO = 1 << 1, ///< zero
        FL_NEG = 1 << 2 ///< negative
    };
}