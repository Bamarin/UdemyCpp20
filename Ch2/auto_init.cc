#include <iostream>

// AAA: Almost Always Auto
// DRY: Don't Repeat Yourself
int main()
{
    // Avoid implicit conversion
    float a = 10.5; // implicitly converted
    std::int32_t b = a; // implicitly converted
    auto b2 = a; // unclear type

    // DO
    auto c = static_cast<std::int32_t>(a); // explicitly converted
    //auto d = std::int32_t{a}; // uniform init
    auto e = std::int32_t{}; // uniform init

    auto f = 10 + 12.5;

    return 0;
}
