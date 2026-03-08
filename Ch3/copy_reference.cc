#include <iostream>
#include <cstdint>
#include <array>

// c++ style arrays
template <std::size_t N>
void print_arrayvalues(const std::array<std::uint32_t, N>& my_array) // input only: const, 8bytes
{
    std:: cout << &my_array << '\n';
    for (std::uint32_t i = 0; i < my_array.size(); i++)
    {
        std::cout << my_array[i] << '\n';
    }
}

template <std::size_t N>
void double_values(std::array<std::uint32_t, N>& my_array) // in and output, no const, but referencce
{
    for (std::uint32_t i = 0; i < my_array.size(); i++)
    {
        my_array[i] *= 2;
    }
}

int main()
{
    auto my_array = std::array<std::uint32_t, 6U>{1,2,3,4,5,6};
    std:: cout << &my_array << '\n';

    print_arrayvalues(my_array);
    double_values(my_array);
    print_arrayvalues(my_array);

    return 0;
}
