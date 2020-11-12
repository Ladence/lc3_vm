#pragma once

#include <memory>

#include "common/Types.h"

namespace lc3_vm::interfaces {
    /**
     * \interface IInstruction
     * \brief interface representing contract for instruction handler
     */
    class IInstruction {
    public:
        /// alias for unique_ptr on interface
        using ptr_t = std::unique_ptr<IInstruction>;

        /**
         * \brief Executes instruction
         * \param instruction instruction (contains arguments for execution)
         * \warning this method modifies Memory and Registers state (via MemoryManager and RegisterManager)
         */
        virtual void operator()(common::Types::instruction_t instruction) = 0;

        virtual ~IInstruction() = default;
    };
}
