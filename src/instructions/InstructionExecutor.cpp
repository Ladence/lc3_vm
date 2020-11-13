#include "InstructionExecutor.h"
#include "hardware/InstructionsSet.h"
#include "instructions/AddInstruction.h"

using namespace lc3_vm::instructions;
using namespace lc3_vm::hardware;
using namespace lc3_vm::common;

void InstructionExecutor::execute(Types::instruction_t instruction)
{
    (*m_instructionHandlers[getInstructionType(instruction)])(instruction);
}

InstructionExecutor::InstructionExecutor()
{
    m_instructionHandlers[InstructionsSet::OP_ADD] = std::make_unique<AddInstruction>();
}

InstructionsSet InstructionExecutor::getInstructionType(Types::instruction_t instruction)
{
    return static_cast<InstructionsSet>(instruction >> 12);
}
