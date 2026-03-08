#include <iostream>
#include <cstdint>


namespace
{
std::uint64_t factorial(const std::uint8_t n)
{
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

static constexpr auto VALUE = 5;

} // namespace

int main()
{
  const auto result1 = factorial(VALUE); // computed at run time
  const auto result2 = factorial(5); // computed at run time


  return 0;
}
