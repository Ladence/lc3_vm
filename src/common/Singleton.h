#pragma once

#include <memory>

namespace lc3_vm::common {
/**
 * \class Singleton template class for non-violating SOLID Singleton pattern
 * \tparam T underlying class you want to be Singleton
 * \warning non guaranteed thread-safety
 */
template<typename T>
class Singleton final
{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    /**
     * \brief Creates underlying object
     * \tparam Args parameter pack for object construction
     * \param args arguments of object constructor
     */
    template<typename... Args>
    static inline void create(Args&&... args)
    {
        if (m_instancePtr) {
            return;
        }

        m_instancePtr = std::make_unique<T>(std::forward(args...));
    }

    /**
     * \brief Gets underlying object
     * \return raw pointer to underlying object
     */
    static inline T* get()
    {
        if (!m_instancePtr) {
            throw std::runtime_error("Instance hasn't been initialized yet!");
        }

        return *m_instancePtr;
    }

private:
    static std::unique_ptr<T> m_instancePtr = nullptr;
};
}
