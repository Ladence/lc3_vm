#include "RegisterManager.h"
#include "common/Constants.h"

using namespace lc3_vm::sysmanagement;

void RegisterManager::setVal(lc3_vm::hardware::RegistersSet reg, common::Types::regval_t val) {
    m_registers[reg] = val;
}

RegisterManager::RegisterManager() {
    m_registers[hardware::RegistersSet::R_PC] = common::Constants::START_POS;
    m_registers[hardware::RegistersSet::R_COUNT] = 0x0000;
    m_registers[hardware::RegistersSet::R_COND] = 0x0000;
    m_registers[hardware::RegistersSet::R_R0] = 0x0000;
    m_registers[hardware::RegistersSet::R_R1] = 0x0000;
    m_registers[hardware::RegistersSet::R_R2] = 0x0000;
    m_registers[hardware::RegistersSet::R_R3] = 0x0000;
    m_registers[hardware::RegistersSet::R_R4] = 0x0000;
    m_registers[hardware::RegistersSet::R_R5] = 0x0000;
    m_registers[hardware::RegistersSet::R_R6] = 0x0000;
    m_registers[hardware::RegistersSet::R_R7] = 0x0000;
}
