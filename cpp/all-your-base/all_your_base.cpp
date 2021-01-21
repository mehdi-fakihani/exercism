#include "all_your_base.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace all_your_base {

    constexpr unsigned int pow(const unsigned int a, const unsigned int b)
    {
        if(b == 0)
            return 1;
        else if(a == 0)
            return 0;
        else
            return a * pow(a, b-1);
    }

    constexpr unsigned int value(const std::vector<unsigned int>& digits, const unsigned int base =  10)
    {
        unsigned int value{0};

        for(std::size_t i = 0; i < digits.size(); ++i)
        {
            const unsigned int power = digits.size() - 1 - i;
            value += digits[i] * pow(base, power);
        }

        return value;
    }

    std::vector<unsigned int> to_base(const unsigned int value, const unsigned int out_base)
    {
        std::vector<unsigned int> result;

        for(unsigned int left_to_convert = value; left_to_convert != 0; left_to_convert /= out_base)
            result.insert(result.begin(), left_to_convert % out_base);

        return result;
    }

    std::vector<unsigned int> convert(const unsigned int in_base, const std::vector<unsigned int>& in_digits, const unsigned int out_base)
    {
        if(in_base < 2)
            throw std::invalid_argument{"Input base must be at least 2"};

        if(out_base < 2)
            throw std::invalid_argument{"Output base must be at least 2"};

        if(std::any_of(in_digits.begin(), in_digits.end(), [in_base](const unsigned int digit){return digit >= in_base;}))
            throw std::invalid_argument{"All input digits must be less than the input base"};

        return in_base == out_base ? in_digits : to_base(value(in_digits, in_base), out_base);
    }
}  // namespace all_your_base
