#include "RegisterManager.h"
#include "common/Constants.h"
#include "hardware/ConditionFlagState.h"

using namespace lc3_vm::sysmanagement;

void RegisterManager::setVal(lc3_vm::hardware::RegistersSet reg, common::Types::regval_t val)
{
    m_registers[static_cast<std::uint8_t>(reg)] = val;
}

RegisterManager::RegisterManager()
{
    m_registers[static_cast<std::size_t>(hardware::RegistersSet::R_PC)] = common::Constants::START_POS;

    for (std::size_t i = 1; i < m_registers.size(); ++i) {
        m_registers[i] = 0x0000;
    }
}

lc3_vm::common::Types::regval_t RegisterManager::getVal(lc3_vm::hardware::RegistersSet reg)
{
    return m_registers[static_cast<std::uint8_t>(reg)];
}
void RegisterManager::updateRCond(lc3_vm::hardware::RegistersSet reg) noexcept
{
    auto regVal = m_registers[static_cast<std::uint8_t>(reg)];
    auto rCondIdx = static_cast<std::uint8_t>(hardware::RegistersSet::R_COND);

    if (regVal == 0) {
        m_registers[rCondIdx] = static_cast<common::Types::regval_t>(hardware::ConditionFlagState::FL_ZRO);
    } else if (regVal >> 15) {
        m_registers[rCondIdx] = static_cast<common::Types::regval_t>(hardware::ConditionFlagState::FL_NEG);
    } else {
        m_registers[rCondIdx] = static_cast<common::Types::regval_t>(hardware::ConditionFlagState::FL_POS);
    }
}
