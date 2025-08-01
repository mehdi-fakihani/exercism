#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H

#include <algorithm>
#include <numeric>
#include <set>

namespace sum_of_multiples {
    [[nodiscard]] unsigned int to(const std::initializer_list<unsigned int>& factors, const unsigned int upper_bound)
    {
        std::set<unsigned int> multiples;
        for (unsigned int current = 0; current < upper_bound; ++current)
        {
            if (std::any_of(std::begin(factors), std::end(factors), [current](const auto factor){ return current % factor == 0; }))
                multiples.insert(current);
        }
        return std::accumulate(std::cbegin(multiples), std::cend(multiples), 0);
    }
}  // namespace sum_of_multiples

#endif // SUM_OF_MULTIPLES_H