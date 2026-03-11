#include <iostream>

enum class Status
{
    Unknown,
    Connected,
    Disconnected,
};

enum class UserPermission
{
    Unknown,
    User,
    Admin,
};

int main()
{
    Status s1 = Status::Unknown;

    switch (s1)
    {

    case Status::Unknown:
        std::cout << "Unknown\n";
        break;

    case Status::Connected:
        std::cout << "Connected\n";
        break;

    case Status::Disconnected:
        std::cout << "Disconnected\n";
        break;

    default:
        break;
    }

    return 0;
}
