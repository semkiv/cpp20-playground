// Still waiting for the following to start working...
// import <cstdlib>;
// import <iostream>;

#include <cstdlib>
#include <iostream>
#include <thread>

auto main([[maybe_unused]] int const argc, [[maybe_unused]] char const * const argv[]) -> int
{
    auto jt = std::jthread{
        [] { std::cout << "Hello C++20 world!" << std::endl; }
    };

    return EXIT_SUCCESS;
}
