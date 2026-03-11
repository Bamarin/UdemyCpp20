#include <iostream>

enum class Status
{
    Unknown,
    Connected,
    Disconnected,
};

// POD
struct User
{
    Status status;
    std::uint16_t id;
};


int main()
{
    //User u1 = {Status::Connected, 42U};
    User u1 = {.status = Status::Connected, .id = 42U}; // C++20

    std::cout << u1.id << '\n';
    std::cout << (std::int32_t)u1.status << '\n';
    std::cout << static_cast<std::int32_t>(u1.status) << '\n';

    return 0;
}
