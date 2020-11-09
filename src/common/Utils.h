#pragma once

#include <cstdint>

namespace lc3_vm::common {
    /**
     * \class Utils
     * \brief class contains static utils methods for application
     */
    class Utils {
    public:
        /**
         * \brief Converts Big Endian to Little Endian
         * \param x source value to convert
         * \return big endian representation of x
         */
        static inline std::uint16_t bswap16(std::uint16_t x) {
            return (x << 8) | (x >> 8);
        }

        /**
         * \brief Sign extend a two's complement number to 16 bits
         * \param x input value
         * \param bitCount bit count
         * \return sign-extended value of x
         */
        static inline std::uint16_t signExtend(std::uint16_t x, int bitCount) {
            if ((x >> (bitCount - 1)) & 1) {
                x |= (0xFFFF << bitCount);
            }

            return x;
        }

        /**
         * \brief Checks whenever system is Little endian or not (on compile-time)
         * \return true if system is little endian, otherwise false
         */
        static constexpr inline bool isLittleEndian() {
            return (0xFFFFFFFF & 1) == 0x00000001;
        }
    };
}