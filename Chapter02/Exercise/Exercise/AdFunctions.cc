#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdFunctions.h"

using namespace Ad;

constexpr float Utils::kph_to_mps(const float kph)
{
    return kph * 1000 / 3600;
}


Types::VehicleType Data::init_ego_vehicle()
{
    Types::VehicleType ego =
    {
        .Id = Constants::EGO_VEHICLE_ID,
        .Lane = Types::LaneAssociationType::Center,
        .Speed = Utils::kph_to_mps(135)
    };

    return ego;
}

void Visualize::print_vehicle(const Types::VehicleType vehicle)
{
    std::cout << "Ego #" << vehicle.Id
    << "\nSpeed: " << vehicle.Speed << " m/s\n"
    << "Distance: " << vehicle.RelativeDistance << " m\n";

}
