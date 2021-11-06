#include <thread>
#include <csignal>

#include <easylogging++.h>

#include "core/VirtualMachine.h"

using namespace lc3_vm;

INITIALIZE_EASYLOGGINGPP

namespace
{
    volatile std::sig_atomic_t g_Done = 0;
}

void sigHandler(int sig)
{
    if (sig == SIGKILL || sig == SIGTERM)
    {
        // graceful
        LOG(INFO) << "Stopping Virtual Machine..." << std::endl;
        g_Done = 1;
    }
}
int main(int argc, char** argv)
{
    START_EASYLOGGINGPP(argc, argv);
    if (argc < 2)
    {
        LOG(ERROR) << "Usage: ./lc3_vm [path_to_executable_image]" << std::endl;
        return 1;
    }

    signal(SIGKILL, sigHandler);

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

    std::thread watchdog{[&vm](){
            while (!g_Done)
            {
                std::this_thread::sleep_for(std::chrono::seconds{5});
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
