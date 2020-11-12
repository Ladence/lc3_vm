#include <optional>
#include "MemoryManager.h"

using namespace lc3_vm::sysmanagement;

std::optional<uint16_t> MemoryManager::read(uint16_t address) {
    if (address >= common::Constants::MEMORY_SIZE) {
        return std::nullopt;
    }

    return m_memory.at(address);
}

bool MemoryManager::write(uint16_t address, uint16_t val) {
    if (address >= common::Constants::MEMORY_SIZE) {
        return false;
    }

    m_memory[address] = val;
    return true;
}
