#include "armstrong_numbers.h"

#include <numeric>
#include <string>

namespace armstrong_numbers {

    constexpr unsigned int pow(const unsigned int a, const unsigned int b)
    {
        if(b == 0)
            return 1;
        else if (a == 0)
            return 0;
        else
            return a * pow(a, b-1);
    }

    bool is_armstrong_number(const unsigned int n)
    {
        const std::string digits = std::to_string(n);

        // We're limited to C++14 so I can't use std::reduce instead of std::accumulate
        return n == std::accumulate(
                                    digits.begin(), digits.end(), 0u,
                                    [&digits](const unsigned int accumulator, const char digit)
                                    {
                                        return accumulator + pow(digit - '0',digits.size());
                                    }
                                );
    }

}  // namespace armstrong_numbers
