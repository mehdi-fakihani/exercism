#pragma once

#include <bitset>
#include <limits>

namespace chicken_coop {
    
    [[nodiscard]] std::size_t positions_to_quantity(const unsigned int encoded_positions)
    {
        return std::bitset<std::numeric_limits<decltype(encoded_positions)>::digits>(encoded_positions).count();
    }
    
}  // namespace chicken_coop
