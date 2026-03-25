#include <cstdint>
#include <iostream>
#include <map>
#include <string>

void print_map(const std::map<std::string, std::int32_t> &map)
{
    for (const auto &[key, val] : map)
    {
        std::cout << key << ": " << val << '\n';
    }
    std::cout << '\n';
}

int main()
{
    auto my_map = std::map<std::string, std::int32_t>{
      {"Leo", 29}
    };

    my_map["Sam"] = 40;
    my_map["Joe"] = 38;

    print_map(my_map);

    my_map["Joe"] = 39;
    print_map(my_map);

    if (!my_map.contains("Sam"))
    {
        my_map["Sam"] = 40;
    }
    if (!my_map.contains("Lisa"))
    {
        my_map["Lisa"] = 36;
    }
    print_map(my_map);

    const auto it_find = my_map.find("Lisa");
    if (it_find != my_map.end())
    {
        std::cout << (*it_find).first << ": " << (*it_find).second << '\n';
    }

    return 0;
}
