#include <iostream>
#include <cstdint>

// static
// local var
// global var
// member var of class
// member func of class

std::uint64_t factorial(const std::uint8_t n)
{
    static std::uint32_t counter = 0;
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++)
    {
        result *= i;
    }

    ++counter;
    std::cout << "Counter: " << counter << "\n";

    return result;
}

int main()
{
  const auto result1 = factorial(5); // computed at run time
  const auto result2 = factorial(5); // computed at run time
  //constexpr auto var = factorial(5); // computed at compile time


  return 0;
}
