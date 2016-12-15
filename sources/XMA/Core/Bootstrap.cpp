#include <XMA/Core/Bootstrap.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

int Bootstrap::run(std::function<void()> callback)
{
    try {

        callback();

    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Oups ... :-(" << std::endl;
    }

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------

}}