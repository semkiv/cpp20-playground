// Still waiting for the following to start working...
// import <cstdlib>;
// import <iostream>;

#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>

class Greeter {
public:
    template<typename Function, typename... Args>
    Greeter(Function && f, Args &&... args)
            : m_worker{std::forward<Function>(f), std::forward<Args>(args)...} {}

private:
    std::jthread m_worker;
};

auto main([[maybe_unused]] int const argc, [[maybe_unused]] char const * const argv[]) -> int {
    auto const greeter = Greeter{[] { std::cout << "Hello C++20 world!" << std::endl; }};

    return EXIT_SUCCESS;
}
