#if !defined(DIFFERENCE_OF_SQUARES_H)
#define DIFFERENCE_OF_SQUARES_H

namespace difference_of_squares {

    // Everything can be simplified with Faulhaber formula

    constexpr unsigned int square_of_sum(const unsigned int n)
    {
        const unsigned int sum = n * (n + 1) / 2;
        return sum * sum;
    }

    constexpr unsigned int sum_of_squares(const unsigned int n)
    {
        return n * (2*n + 1) * (n + 1) / 6;
    }

    constexpr unsigned int difference(const unsigned int n)
    {
        return n * (n+1) * (3*n + 2) * (n - 1) / 12;
    }

}  // namespace difference_of_squares

#endif // DIFFERENCE_OF_SQUARES_H
