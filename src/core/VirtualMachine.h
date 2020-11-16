#pragma once

#include <memory>

#include "common/Types.h"
#include "interfaces/IInstructionExecutor.h"

namespace lc3_vm::core {

/**
 * \class VirtualMachine
 * \brief Class representing core class for Virtual Machine launching
 */
class VirtualMachine
{
    bool loadImageFile(const std::string& imageFilePath) noexcept;

    common::Types::instruction_t fetchInstruction();

public:
    /**
     * \brief Launches virtual machine's work
     */
    void launch();

    /**
     * \brief initializes resources for virtual machine
     * \return true if initialization has been succeed, otherwise false
     */
    bool boot();

    /**
     * \brief Stops virtual machine
     */
    void halt();

private:
    std::unique_ptr<interfaces::IInstructionExecutor> m_instructionExecutor;

    std::atomic_flag m_running = ATOMIC_FLAG_INIT;
};

}