#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

#include "AdConstants.h"
#include "AdFunctions.h"

using namespace Ad;
using namespace Ad::Constants;

namespace Ad
{
    namespace Utils
    {
        constexpr float kph_to_mps(const float kph)
        {
            return kph * 1000 / 3600;
        }

    }

    namespace Data
    {
        Types::VehicleType init_ego_vehicle()
        {
            Types::VehicleType ego =
            {
                .Id = Constants::EGO_VEHICLE_ID,
                .Lane = Types::LaneAssociationType::Center,
                .Speed = Utils::kph_to_mps(135),
                .RelativeDistance = 0
            };

            return ego;
        }

        Types::NeighborVehiclesType init_vehicles()
        {
            auto vehicles = Types::NeighborVehiclesType{};

            for(size_t i=0; i<2; i++)
            {
                vehicles.leftVehicles[i] =
                {
                    .Id = i*3,
                    .Lane = Types::LaneAssociationType::Left,
                    .Speed = Utils::kph_to_mps(100+i*30),
                    .RelativeDistance = static_cast<float>((pow(-1,(i+1))*60+30))
                };
                vehicles.centerVehicles[i] =
                {
                    .Id = i*3+1,
                    .Lane = Types::LaneAssociationType::Center,
                    .Speed = Utils::kph_to_mps(80+i*60),
                    .RelativeDistance = static_cast<float>((pow(-1,(i+1))*80))
                };
                vehicles.rightVehicles[i] =
                {
                    .Id = i*3+2,
                    .Lane = Types::LaneAssociationType::Right,
                    .Speed = Utils::kph_to_mps(100+10*i),
                    .RelativeDistance = static_cast<float>((pow(-1,(i+1))*45-20))
                };
            }
            return vehicles;
        }
    }

    namespace Visualize
    {

        void print_vehicle(const Types::VehicleType &vehicle)
        {
            std::cout << "Vehicle #" << vehicle.Id
            << "\nSpeed: " << vehicle.Speed << " m/s\n"
            << "Distance: " << vehicle.RelativeDistance << " m\n";
        }

        void print_neighbor_vehicles(const Types::NeighborVehiclesType &vehicles)
        {
            for(size_t i=0; i<NUM_VEHICLES_ON_LANE; i++)
            {
                print_vehicle(vehicles.leftVehicles[i]);
                print_vehicle(vehicles.centerVehicles[i]);
                print_vehicle(vehicles.rightVehicles[i]);
            }
        }

        void print_row_distance(float distance, const Types::NeighborVehiclesType &vehicles, const Types::LaneAssociationType ego_lane)
        {
            bool detectedL = false;
            bool detectedC = false;
            bool detectedR = false;
            for(auto v : vehicles.leftVehicles)
            {
                auto vDist = v.RelativeDistance;
                detectedL |= (vDist <= distance && vDist > distance - 20);
            }
            for(auto v : vehicles.centerVehicles)
            {
                auto vDist = v.RelativeDistance;
                detectedC |= (vDist <= distance && vDist > distance - 20);
            }
            for(auto v : vehicles.rightVehicles)
            {
                auto vDist = v.RelativeDistance;
                detectedR |= (vDist <= distance && vDist > distance - 20);
            }

            char L = detectedL ? 'V' : ' ';
            char C = detectedC ? 'V' : ' ';
            char R = detectedR ? 'V' : ' ';

            if(distance == 0)
            {
                switch(ego_lane)
                {
                    case Types::LaneAssociationType::Left:
                        L = detectedL ? 'X' : 'E';
                        break;
                    case Types::LaneAssociationType::Center:
                        C = detectedC ? 'X' : 'E';
                        break;
                    case Types::LaneAssociationType::Right:
                        R = detectedR ? 'X' : 'E';
                        break;
                    default:
                        break;
                }
            }
            std::cout << distance << "\t| " << L << " | " << C << " | " << R << " |\n";
        }

        void print_scene(const Types::VehicleType &ego_vehicle,
                        const Types::NeighborVehiclesType &vehicles)
        {
            std::cout << "\t  L   C   R  \n";
            for(int8_t row = 100; row >= -100; row -= 20)
            {
                print_row_distance(row, vehicles, ego_vehicle.Lane);
            }
        }

    } // namespace Visualize
} // namespace Add
