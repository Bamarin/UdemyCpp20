#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <string>
#include <vector>
#include <utility>
#include <tuple>

struct DataBlaBla
{
    std::int32_t i;
    float j;
};

std::tuple<std::int32_t, float, std::string> some_function(const std::int32_t input)
{
    return std::make_tuple(input, static_cast<float>(input), std::to_string(input));
}

DataBlaBla some_function2(const std::int32_t input)
{
    return DataBlaBla{input, static_cast<float>(input + 0.5F)};
}

int main()
{
    auto my_pair = std::pair<std::int32_t, float>{1447, 42.0F};
    std::cout << my_pair.first << '\n';
    std::cout << my_pair.second << '\n';

    auto my_tuple = std::tuple<std::int32_t, float, std::string>
                    { 1337, 42.0F, "Leo" };
    std::cout << std::get<0>(my_tuple) << '\n';
    std::cout << std::get<1>(my_tuple) << '\n';
    std::cout << std::get<2>(my_tuple) << '\n';

    const auto result = some_function(42);
    std::cout << std::get<0>(result) << '\n';
    std::cout << std::get<1>(result) << '\n';
    std::cout << std::get<2>(result) << '\n';

    const auto &[i, f, s] = some_function(42); // Structured Binding
    std::cout << i << '\n';
    std::cout << f << '\n';
    std::cout << s << '\n';

    const auto &[i1, f1] = some_function2(42);
    std::cout << i1 << '\n';
    std::cout << f1 << '\n';

    return 0;
}
