#pragma once

#include <cstdint>

namespace lc3_vm::common {
/**
 * \class Types
 * \brief Utils-class which contains only aliases
 */
class Types
{
public:
    using instruction_t = std::uint16_t; ///< according to specification, this VM can process 16-bit instructions
    using regval_t = std::uint16_t;      ///< according to specification, this VM contain 16-bit registers
};
}