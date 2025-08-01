#if !defined(RAINDROPS_H)
#define RAINDROPS_H

#include <string>

namespace raindrops {
    [[nodiscard]] std::string convert(const unsigned int number)
    {
        std::string result;
        
        if (number % 3 == 0)
            result += "Pling";
        
        if (number % 5 == 0)
            result += "Plang";
        
        if (number % 7 == 0)
            result += "Plong";
        
        return result.empty() ? std::to_string(number) : result;
    }
}  // namespace raindrops

#endif // RAINDROPS_H