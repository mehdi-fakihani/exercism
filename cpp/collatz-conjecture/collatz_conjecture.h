#if !defined(COLLATZ_CONJECTURE_H)
#define COLLATZ_CONJECTURE_H

#include <stdexcept>

namespace collatz_conjecture {
    constexpr unsigned int steps(const int seed)
    {
        if (seed < 1)
            throw std::domain_error{"Invalid seed"};
        else
            return seed == 1 ? 0 : 1 + steps(seed % 2 == 0 ? seed / 2 : 3*seed + 1);
    }
}  // namespace collatz_conjecture

#endif // COLLATZ_CONJECTURE_H
