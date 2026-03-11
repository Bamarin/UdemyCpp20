#include <iostream>

//5! = 5 * 4 * 3 * 2 * 1
// const: read only input
// contsexpr: const +
std::uint64_t factorial(const std::uint8_t n)
{
    auto res = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n: i++)
    {
        res *= i;
    }

    return res;
}

int main()
{
    const auto result = factorial(5);

    constexpr auto var = 5 * 3 * 2;

    return 0;
}
