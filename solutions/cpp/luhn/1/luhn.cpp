#include "luhn.h"

#include <algorithm>
#include <cctype>

#include <iostream>

namespace luhn
{
    bool valid(std::string_view number)
    {
        constexpr std::size_t minimum_size = 2;
        std::size_t digits_number = 0;
        
        auto accumulator = 0;
        bool odd_index = true;
        
        for (auto iterator = std::crbegin(number); iterator != std::rend(number); ++iterator)
        {
            if (std::isspace(*iterator)) continue;
            if (*iterator < '0' || *iterator > '9') return false;
            
            const std::uint8_t digit = *iterator - '0';
            accumulator += digit * (2 - odd_index) - 9 * (!odd_index && digit > 4);
            
            ++digits_number;
            odd_index = !odd_index;
        }

        std::cout << "ACCUMULATOR = " << accumulator;
        return digits_number >= minimum_size && (accumulator % 10) == 0;
    }
} // namespace luhn