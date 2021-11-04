#include <gtest/gtest.h>

#include "common/Singleton.h"
#include "common/Types.h"
#include "sysmanagement/MemoryManager.h"
#include "sysmanagement/RegisterManager.h"
#include "instructions/AddInstruction.h"

using namespace lc3_vm;

struct TestAddInstruction : ::testing::Test
{
public:
protected:
    virtual void SetUp()
    {
        common::Singleton<sysmanagement::RegisterManager>::create();
        common::Singleton<sysmanagement::MemoryManager>::create();
    }
};

TEST_F(TestAddInstruction, TestAddInstruction_R1R1_Success)
{
    constexpr common::Types::instruction_t INSTRUCTION = 0x1261;

    instructions::AddInstruction addInstruction;
    auto& regMngr = common::Singleton<sysmanagement::RegisterManager>::get();
    regMngr.setVal(hardware::RegistersSet::R_R1, 9);
    addInstruction(INSTRUCTION);

    auto val = regMngr.getVal(lc3_vm::hardware::RegistersSet::R_R1);
    ASSERT_EQ(val, 10);
}
