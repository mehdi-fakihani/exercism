#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {
    enum struct flavor
    {
        equilateral,
        isosceles,
        scalene
    };
    
    [[nodiscard]] static constexpr flavor kind(const double a, const double b, const double c)
    {
        if (a == 0 && b == 0 && c == 0) throw std::domain_error("degenerate case: all sides are zero, it's a point");
        if ( a > b + c || b > a + c || c > a + b ) throw std::domain_error{ "triangle inequality unsatisfied"};
        
        if (a == b && b == c) return flavor::equilateral;
        if (a == b || a == c || b == c) return flavor::isosceles;
        return flavor::scalene;
    }
}  // namespace triangle

#endif // TRIANGLE_H