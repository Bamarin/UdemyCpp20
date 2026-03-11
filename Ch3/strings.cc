#include <array>
#include <cstdint>
#include <iostream>
#include <string>

int main()
{
    char single_character = 'a';
    char my_text1[] = "Leo";
    char my_text2[] = {'L', 'e', 'o', '\0'}; // \0 null terminating
    auto my_text3 = std::array<char, 4>{"Leo"};

    auto my_array4 = std::string{"Leo"};
    std::cout << my_array4.size() << "\n";
    my_array4.append(" Marini");
    std::cout << my_array4.size() << "\n";

    /* Modern C++
       my_text1
       my_text4
    */


    return 0;
}
