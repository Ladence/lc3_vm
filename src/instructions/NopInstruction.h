#pragma once

#include <easylogging++.h>

#include "interfaces/IInstruction.h"

namespace lc3_vm::instructions {
/**
 * \class NopInstruction
 * \implements interfaces::IInstruction
 * \brief NOP instruction - does nothing :)
 */
class NopInstruction : public interfaces::IInstruction
{
public:
    /**
     * \copydoc interfaces::IInstruction::operator()(common::Types::instruction_t)
     */
    inline void operator()(common::Types::instruction_t instruction) override
    {
    }

    ~NopInstruction() override = default;
};
}