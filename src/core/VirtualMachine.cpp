#include "VirtualMachine.h"

using namespace lc3_vm::core;

VirtualMachine::VirtualMachine(std::unique_ptr<interfaces::IRegisterManager> &&regManager,
                               std::unique_ptr<interfaces::IMemoryManager> &&memManager) : m_regManager{std::move(regManager)}, m_memManager{std::move(memManager)} {
    m_running.test_and_set(std::memory_order_relaxed);

}

void VirtualMachine::halt() {
    m_running.clear(std::memory_order_relaxed);
}

void VirtualMachine::launch() {
while (m_running.test_and_set()) {
    auto instr = fetchInstruction();
}
}

lc3_vm::common::Types::instruction_t VirtualMachine::fetchInstruction() {
    auto pcCurrState = m_regManager->getVal(hardware::RegistersSet::R_PC);

    if (!pcCurrState) {
        throw std::runtime_error("Something went wrong with PC Register!");
    }

    ++*pcCurrState;
    m_regManager->setVal(hardware::RegistersSet::R_PC, *pcCurrState);

    return m_memManager->read(*pcCurrState);
}
