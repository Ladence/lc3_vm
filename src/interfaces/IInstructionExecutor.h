#pragma once

#include "common/Types.h"

namespace lc3_vm::interfaces {
/**
 * \interface IInstructionExecutor
 * \brief Interface representing contract for InstructionExecutor unit
 */
class IInstructionExecutor
{
public:
    /**
     * \brief Executes given instruction
     * \param instruction instruction to execute
     * \warning This member function throws an exception if memory write fails
     */
    virtual void execute(common::Types::instruction_t instruction) = 0;

    virtual ~IInstructionExecutor() = default;
};
}
