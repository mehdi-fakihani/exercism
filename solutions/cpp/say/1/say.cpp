#include "say.h"

#include <stdexcept>

namespace say {

    std::string unit_in_english(const unsigned long long int& number)
    {
        switch(number)
        {
            case 0:
                return "zero";
            case 1:
                return "one";
            case 2:
                return "two";
            case 3:
                return "three";
            case 4:
                return "four";
            case 5:
                return "five";
            case 6:
                return "six";
            case 7:
                return "seven";
            case 8:
                return "eight";
            case 9:
                return "nine";
            default:
                return "";
        }
    }

    std::string teen_in_english(const unsigned long long int& number)
    {
        switch(number)
        {
            case 10:
                return "ten";
            case 11:
                return "eleven";
            case 12:
                return "twelve";
            case 13:
                return "thirteen";
            case 14:
                return "fourteen";
            case 15:
                return "fifteen";
            case 16:
                return "sixteen";
            case 17:
                return "seventeen";
            case 18:
                return "eighteen";
            case 19:
                return "nineteen";
            default:
                return "";
        }
    }

    std::string tens_in_english(const unsigned long long int& number)
    {
        switch(number / 10)
        {
            case 2:
                return "twenty";
            case 3:
                return "thirty";
            case 4:
                return "forty";
            case 5:
                return "fifty";
            case 6:
                return "sixty";
            case 7:
                return "seventy";
            case 8:
                return "eighty";
            case 9:
                return "ninety";
            default:
                return "";
        }
    }

    std::string in_english(const unsigned long long int& number)
    {
        if (number < 0 || 1'000'000'000'000 <= number)
            throw std::domain_error("Only numbers between 0 and 999 999 999 (included)");
        else
        {
            if (number < 10)
                return unit_in_english(number);
            else if (number < 20)
                return teen_in_english(number);
            else if (number < 100)
                return tens_in_english(number) + (number % 10 != 0 ? "-" + in_english(number % 10) : "");
            else if (number < 1000)
                return unit_in_english(number / 100) + " hundred" + (number % 100 != 0 ? " " + in_english(number % 100) : "");
            else if (number < 1'000'000)
                return in_english(number / 1'000) + " thousand" + (number % 1'000 != 0 ?  " " + in_english(number % 1'000) : "");
            else if (number < 1'000'000'000)
                return in_english(number / 1'000'000) + " million" + (number % 1'000'000 != 0 ?  " " + in_english(number % 1'000'000) : "");
            else
                return in_english(number / 1'000'000'000) + " billion" + (number % 1'000'000'000 != 0 ?  " " + in_english(number % 1'000'000'000) : "");
        }
    }

}  // namespace say
