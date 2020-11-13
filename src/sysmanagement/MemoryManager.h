#pragma once

#include <array>
#include <optional>

#include "common/Constants.h"

namespace lc3_vm::sysmanagement {
/**
 * \class MemoryManager
 * \implements IMemoryManager
 * \brief class for memory management of LC3's system
 */
class MemoryManager
{
public:
    /**
     * \copydoc interfaces::IMemoryManager::read(uint16_t)
     * todo: fix doc
     */
    std::optional<uint16_t> read(uint16_t address) noexcept;

    /**
     * \copydoc interfaces::IMemoryManager::write(uint16_t, uint16_t)
     * todo: fix doc
     */
    bool write(uint16_t address, uint16_t val) noexcept;

private:
    std::array<common::Types::regval_t, common::Constants::MEMORY_SIZE> m_memory;
};
}