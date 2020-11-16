#pragma once

#include <cstdint>
#include <unordered_map>

#include "hardware/InstructionsSet.h"
#include "interfaces/IInstruction.h"
#include "interfaces/IInstructionExecutor.h"

namespace lc3_vm::instructions {

/**
 * \class InstructionExecutor
 * \implements interfaces::IInstructionExecutor
 * \brief This class implements logic of instructions executing
 */
class InstructionExecutor : public interfaces::IInstructionExecutor
{
    static hardware::InstructionsSet getInstructionType(common::Types::instruction_t instruction);

public:
    /**
     * \brief Constructor. Creates and fills mapping [Instruction -> Instruction handler]
     */
    InstructionExecutor();

    /**
     * \copydoc interfaces::IInstructionExecutor::execute(std::uint16_t)
     */
    void execute(common::Types::instruction_t instruction) override;

    ~InstructionExecutor() override = default;

private:
    std::unordered_map<hardware::InstructionsSet, interfaces::IInstruction::ptr_t> m_instructionHandlers;
};

}