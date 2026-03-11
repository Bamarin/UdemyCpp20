#include <iostream>
#include <cstdint>

// read only input
// constexpr: const +
constexpr std::uint64_t factorial(const std::uint8_t n)
{
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int main()
{
    const auto result1 = factorial(5); // computed at run time
    constexpr auto var = factorial(5); // computed at compile time

    return 0;
}
