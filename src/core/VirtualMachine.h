#pragma once

#include <memory>

#include "interfaces/IRegisterManager.h"
#include "interfaces/IMemoryManager.h"

namespace lc3_vm::core {

    /**
     * \class VirtualMachine
     * \brief Class representing core class for Virtual Machine launching
     */
    class VirtualMachine {
        bool loadImageFile(const std::string& imageFilePath) noexcept;

        common::Types::instruction_t fetchInstruction();

    public:
        /**
         * \brief Constructs the VirtualMachine's object
         * \param regManager
         * \param memManager
         */
        VirtualMachine(std::unique_ptr<interfaces::IRegisterManager> &&regManager,
                       std::unique_ptr<interfaces::IMemoryManager> &&memManager);

        /**
         * \brief Launches virtual machine's work
         */
        void launch();

        /**
         * \brief Stops virtual machine
         */
        void halt();

    private:
        std::unique_ptr<interfaces::IRegisterManager> m_regManager;
        std::unique_ptr<interfaces::IMemoryManager> m_memManager;

        std::atomic_flag m_running = ATOMIC_FLAG_INIT;
    };

}