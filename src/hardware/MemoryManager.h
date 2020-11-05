#pragma once

#include "IMemoryManager.h"

namespace lc3_vm::hardware {
    /**
     * \class MemoryManager
     * \implements IMemoryManager
     * \brief class for memory management of LC3's system
     */
    class MemoryManager : public IMemoryManager {
    public:
        /**
         * \copydoc IMemoryManager::read(uint16_t)
         */
        uint16_t read(uint16_t address) override;

        /**
         * \copydoc IMemoryManager::write(uint16_t, uint16_t)
         */
        bool write(uint16_t address, uint16_t val) override;

        ~MemoryManager() override = default;
    };
}