#include <array>
#include <cstdint>
#include <iostream>

int main()
{
    /* Stack: default, simpler, fixed memory size
     * auto len = 5U;
     * std::uint32_t my_array[len] = {1, 2, 3, 4, 5}; // ERROR: can't use variable length
     */

    // Heap: complex, variable size
    auto len2 = std::size_t{};
    std::cin >> len2;

    std::uint32_t *heap_arr = new std::uint32_t[len2];
    std::cout << heap_arr << '\n';

    for(std::size_t i = 0; i < len2; i++)
    {
        heap_arr[i] = static_cast<std::uint32_t>(i);
    }

    for(std::size_t i = 0; i < len2; i++)
    {
        std::cout << heap_arr[i] << '\n';
    }

    delete[] heap_arr; // free the heap memory
    heap_arr = nullptr; // set to nullptr to check if it contains a value

    if (heap_arr == nullptr)
    {
        return 1;
    }
    else if (heap_arr)
    {
        std::cout << heap_arr[1];
    }


    return 0;
}
