#include <XMA/Core/Bootstrap.hpp>
#include <XMA/Core/Debug.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

int Bootstrap::run(std::function<void()> callback)
{
    XMA_LOG();

    try {

        callback();

    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Oups ... :-(" << std::endl;
    }

    XMA_DUMP_LOG();

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------

}}