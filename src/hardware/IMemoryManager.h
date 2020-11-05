#pragma once

#include <cstdint>

namespace lc3_vm::hardware {
    /**
     * \interface IMemoryManager
     * \brief interface representing contract for MemoryManager impl
     */
    class IMemoryManager {
    public:
        /**
         * \brief Reads the memory's cell content
         * \param address address for reading
         * \return content of memory cell by `address` parameter
         */
        uint16_t read(uint16_t address) noexcept ;

        /**
         * \brief Writes value to a memory cell
         * \param address address of memory for writing content
         * \param val content to write
         * \return true if succeeds, false otherwise
         */
        bool write(uint16_t address, uint16_t val) noexcept ;
    };
}