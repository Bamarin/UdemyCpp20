#pragma once

#include <cstdint>
#include <array>

#include "AdConstants.h"

using namespace Ad::Constants;

namespace Ad::Types
{

    enum class LaneAssociationType
    {
        Unknown,
        Left,
        Center,
        Right
    };

    struct VehicleType
    {
        std::int32_t Id;
        LaneAssociationType Lane;
        float Speed;
        float RelativeDistance;
    };

    struct NeighborVehiclesType
    {
        std::array<VehicleType, NUM_VEHICLES_ON_LANE> leftVehicles;
        std::array<VehicleType, NUM_VEHICLES_ON_LANE> centerVehicles;
        std::array<VehicleType, NUM_VEHICLES_ON_LANE> rightVehicles;
    };

} // namespace Ad::Types
