#include <fstream>
#include <vector>

#include "VirtualMachine.h"
#include "common/Constants.h"
#include "common/Singleton.h"
#include "common/Utils.h"
#include "instructions/InstructionExecutor.h"
#include "sysmanagement/MemoryManager.h"
#include "sysmanagement/RegisterManager.h"

using namespace lc3_vm::core;
using namespace lc3_vm::common;
using namespace lc3_vm::sysmanagement;

void VirtualMachine::halt()
{
    m_running.clear(std::memory_order_relaxed);
}

void VirtualMachine::launch()
{
    while (m_running.test_and_set()) {
        auto instr = fetchInstruction();

        m_instructionExecutor->execute(instr);
    }
}

lc3_vm::common::Types::instruction_t VirtualMachine::fetchInstruction()
{
    auto& regManager = Singleton<RegisterManager>::get();
    auto& memManager = Singleton<MemoryManager>::get();

    auto pcCurrState = regManager.getVal(hardware::RegistersSet::R_PC);

    ++pcCurrState;
    regManager.setVal(hardware::RegistersSet::R_PC, pcCurrState);

    auto instruction = memManager.read(pcCurrState);
    if (!instruction) {
        throw std::runtime_error("Something went wrong when trying to fetch instruction from memory!");
    }

    return *instruction;
}

bool VirtualMachine::loadImageFile(const std::string& imageFilePath) noexcept
{
    std::ifstream ifs{ imageFilePath, std::ios::binary };

    if (!ifs.is_open()) {
        return false;
    }
    std::uint16_t origin;
    ifs >> origin;

    constexpr bool isLittleEndian = Utils::isLittleEndian();

    if constexpr (isLittleEndian) {
        origin = common::Utils::bswap16(origin);
    }

    ifs.seekg(0, std::ios::end);
    std::size_t buffSz = ifs.tellg();
    ifs.seekg(sizeof origin, std::ios::beg);

    std::vector<std::uint16_t> buffer(buffSz / 2);
    ifs.read(reinterpret_cast<char*>(buffer.data()), buffSz);

    for (std::size_t i = 0; i < buffer.size(); ++i) {
        if constexpr (isLittleEndian) {
            buffer[i] = Utils::bswap16(buffer[i]);
        }

        Singleton<MemoryManager>::get().write(origin + i, buffer[i]);
    }

    return true;
}

bool VirtualMachine::boot()
{
    Singleton<RegisterManager>::create();
    Singleton<MemoryManager>::create();

    m_instructionExecutor = std::make_unique<instructions::InstructionExecutor>();

    m_running.test_and_set(std::memory_order_relaxed);

    return true;
}
