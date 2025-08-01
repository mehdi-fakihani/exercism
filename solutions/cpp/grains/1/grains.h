#if !defined(GRAINS_H)
#define GRAINS_H

#include <cstdint>
#include <limits>

namespace grains {
    [[nodiscard]] constexpr unsigned long long int square(const unsigned int index)
    {
        return 1ULL << (index - 1);
    }

    [[nodiscard]] constexpr unsigned long long int total()
    {
        return std::numeric_limits<std::uint64_t>::max();
    }
}  // namespace grains

#endif // GRAINS_H