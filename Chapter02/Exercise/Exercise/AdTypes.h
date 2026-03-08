#pragma once

#include <cstdint>

#include "AdConstants.h"

namespace Ad
{
    namespace Types
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
            public: std::int32_t Id;
            LaneAssociationType Lane;
            double Speed;
            std::int32_t RelativeDistance;
        };

    } // namespace Ad::Types

} // namepace Ad
