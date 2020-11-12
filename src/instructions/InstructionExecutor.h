#pragma once

#include <cstdint>
#include "interfaces/IInstructionExecutor.h"

namespace lc3_vm::instructions {

    /**
     * \class InstructionExecutor
     * \implements interfaces::IInstructionExecutor
     * \brief This class implements logic of instructions executing
     */
    class InstructionExecutor : public interfaces::IInstructionExecutor {
    public:
        /**
         * \copydoc interfaces::IInstructionExecutor::execute(std::uint16_t)
         */
        void execute(std::uint16_t instruction) override;

        ~InstructionExecutor() override = default;
    };

}