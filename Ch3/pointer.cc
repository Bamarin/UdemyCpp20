#include <array>
#include <cstdint>
#include <iostream>

int main()
{
    auto my_age = std::uint32_t{29U}; // de4c: 30
    std::cout << my_age << '\n';

    std::uint32_t* pointer_to_some_data = &my_age; //de50: de4c
    std::cout << &pointer_to_some_data << '\n';

    *pointer_to_some_data = 30;
    std::cout << my_age << '\n';

    return 0;
}
