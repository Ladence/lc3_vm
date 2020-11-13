#pragma once

#include <array>

#include "common/Constants.h"
#include "interfaces/IMemoryManager.h"

namespace lc3_vm::sysmanagement {
/**
 * \class MemoryManager
 * \implements IMemoryManager
 * \brief class for memory management of LC3's system
 */
class MemoryManager : public interfaces::IMemoryManager
{
public:
    /**
     * \copydoc interfaces::IMemoryManager::read(uint16_t)
     */
    std::optional<uint16_t> read(uint16_t address) noexcept override;

    /**
     * \copydoc interfaces::IMemoryManager::write(uint16_t, uint16_t)
     */
    bool write(uint16_t address, uint16_t val) noexcept override;

    ~MemoryManager() override = default;

private:
    std::array<common::Types::regval_t, common::Constants::MEMORY_SIZE> m_memory;
};
}