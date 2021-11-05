#pragma once

#include <cstdint>

namespace lc3_vm::hardware {
/**
 * \enum InstructionType
 * \brief consists of LC3's ISA
 */
enum class InstructionType : std::uint8_t
{
    OP_BR = 0, ///< branch
    OP_ADD,    ///< add
    OP_LD,     ///< load
    OP_ST,     ///< store
    OP_JSR,    ///< jump register
    OP_AND,    ///< bitwise and
    OP_LDR,    ///< load register
    OP_STR,    ///< store register
    OP_RTI,    ///< unused
    OP_NOT,    ///< bitwise not
    OP_LDI,    ///< load indirect
    OP_STI,    ///< store indirect
    OP_JMP,    ///< jump
    OP_RES,    ///< reserved (unused)
    OP_LEA,    ///< load effective address
    OP_TRAP,   ///< executive trap
    OP_NOP     ///< NOP
};
}