#if !defined(DARTS_H)
#define DARTS_H

#include <cmath>

namespace darts {
    [[nodiscard]] static constexpr double distance(const double x, const double y)
    {
        return std::sqrt(x*x + y*y);
    }
    
    [[nodiscard]] static constexpr unsigned int score(const double x, const double y)
    {
        const auto distance_from_center = distance(x,y);
        if (distance_from_center <= 1)
            return 10;
        if (distance_from_center <= 5)
            return 5;
        if (distance_from_center <= 10)
            return 1;
        return 0;
    }
} // namespace darts

#endif //DARTS_H