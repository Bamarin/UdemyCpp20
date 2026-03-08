#pragma once

#include "AdTypes.h"

namespace Ad
{
    namespace Utils
    {
        constexpr float kph_to_mps(const float kph);
    } // namespace Ad::Utils

    namespace Data
    {
        Types::VehicleType init_ego_vehicle();
    } // namespace Ad::Data

    namespace Visualize
    {
        void print_vehicle(const Types::VehicleType vehicle);
    } // namespace Ad::Visualize
} // namespace Ad
