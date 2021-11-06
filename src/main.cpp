#include <thread>
#include <csignal>

#include <easylogging++.h>

#include "core/VirtualMachine.h"

using namespace lc3_vm;

INITIALIZE_EASYLOGGINGPP

namespace
{
    volatile std::atomic_flag g_Done = ATOMIC_FLAG_INIT;
}

void sigHandler(int sig)
{
        // graceful
        LOG(INFO) << "Stopping Virtual Machine..." << std::endl;
        g_Done.clear();
}

void initSignal()
{
    struct sigaction action{};
    action.sa_handler = sigHandler;
    sigemptyset(&action.sa_mask);
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGINT, &action, NULL);
}

int main(int argc, char** argv)
{
    START_EASYLOGGINGPP(argc, argv);
    if (argc < 2)
    {
        LOG(ERROR) << "Usage: ./lc3_vm [path_to_executable_image]" << std::endl;
        return 1;
    }

    initSignal();

    core::VirtualMachine vm;
    if (!vm.boot()) {
        LOG(ERROR) << "Error on booting of virtual machine!" << std::endl;
        return 1;
    }

    LOG(INFO) << "Loading " << argv[1] << " image" << std::endl;
    if (!vm.loadImageFile(argv[1]))
    {
        LOG(ERROR) << "Error on loading executable image to virtual machine!" << std::endl;
        return 1;
    }

    g_Done.test_and_set();
    std::thread watchdog{[&vm](){
            constexpr std::uint8_t WATCHDOG_PERIOD_SEC = 5;
            while (g_Done.test_and_set())
            {
                LOG(INFO) << "VM is working";
                std::this_thread::sleep_for(std::chrono::seconds{WATCHDOG_PERIOD_SEC});
            }
            vm.halt();
        }
    };
    if (watchdog.joinable())
    {
        watchdog.detach();
    }

    vm.launch();
    return 0;
}
