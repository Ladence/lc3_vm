#include "InstructionExecutor.h"
#include "BitwiseAndInstruction.h"
#include "BitwiseNotInstruction.h"
#include "BranchInstruction.h"
#include "LdiInstruction.h"
#include "NopInstruction.h"
#include "hardware/InstructionType.h"
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
    m_instructionHandlers[InstructionType::OP_ADD] = std::make_unique<AddInstruction>();
    m_instructionHandlers[InstructionType::OP_AND] = std::make_unique<BitwiseAndInstruction>();
    m_instructionHandlers[InstructionType::OP_NOT] = std::make_unique<BitwiseNotInstruction>();
    m_instructionHandlers[InstructionType::OP_BR] = std::make_unique<BranchInstruction>();
    m_instructionHandlers[InstructionType::OP_LDI] = std::make_unique<LdiInstruction>();

    // todo: not supported for now (NOP)
    m_instructionHandlers[InstructionType::OP_LD] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_ST] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_JSR] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_LDR] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_STR] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_JMP] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_LEA] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_TRAP] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_STI] = std::make_unique<NopInstruction>();
    m_instructionHandlers[InstructionType::OP_RTI] = std::make_unique<NopInstruction>();
}

InstructionType InstructionExecutor::getInstructionType(Types::instruction_t instruction)
{
    return instruction == 0 ? InstructionType::OP_NOP : static_cast<InstructionType>(instruction >> 12);
}
