#include <array>
#include <cstdint>
#include <iostream>

// c-style array decays to a pointer when passed into a function
void print_arrayvalues1(const std::uint32_t *my_array, const std::uint32_t len)
{
    for (std::uint32_t i = 0; i < len; i++)
    {
        std::cout << my_array[i] << "\n";
    }
}

// c++ style arrays
template <std::size_t N>
void print_arrayvalues2(const std::array<std::uint32_t, N> my_array)
{
    for (std::uint32_t i = 0; i < my_array.size(); i++)
    {
        std::cout << my_array[i] << "\n";
    }
}

int main()
{
    constexpr auto len = 5U;
    std::uint32_t my_array[len] = {1, 2, 3, 4, 5}; // c-style

    print_arrayvalues1(my_array, len);

    auto my_array2 = std::array<std::uint32_t, len>{6, 7, 8, 9, 10};
    print_arrayvalues2(my_array2);

    auto my_array3 = std::array<std::uint32_t, 6U>{};
    print_arrayvalues2(my_array3);

    return 0;
}
