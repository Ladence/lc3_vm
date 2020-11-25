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

protected:
    /**
     * \brief Fetches instruction using R_PC register
     * \details virtual member function for overloading in case of extended Virtual Machine (Template Method pattern)
     * \return next instruction to execute
     */
    virtual common::Types::instruction_t fetchInstruction();

    /**
     * \brief Loads binary image into virtual machine's memory
     * \details virtual member function for overloading in case of extended Virtual Machine (Template Method pattern)
     * \param imageFilePath path to binary image
     * \return true if load succeed, otherwise false
     */
    virtual bool loadImageFile(const std::string& imageFilePath) noexcept;

private:
    std::unique_ptr<interfaces::IInstructionExecutor> m_instructionExecutor;

    std::atomic_flag m_running = ATOMIC_FLAG_INIT;
};

}