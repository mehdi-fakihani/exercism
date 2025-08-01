#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H

#include <algorithm>

namespace sum_of_multiples {
    [[nodiscard]] static constexpr unsigned int to(const std::initializer_list<unsigned int>& factors, const unsigned int upper_bound)
    {
        unsigned int result = 0;
        for (unsigned int current = 1; current < upper_bound; ++current)
        {
            if (std::any_of(std::begin(factors), std::end(factors), [current](const auto factor){ return current % factor == 0; }))
            {
                result += current;
            }
        }
        return result;
    }
}  // namespace sum_of_multiples

#endif // SUM_OF_MULTIPLES_H