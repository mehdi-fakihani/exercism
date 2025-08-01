#include "pascals_triangle.h"

namespace pascals_triangle {

    constexpr int factorial(const int n)
    {
        return n == 0 ? 1 : n * factorial(n-1);
    }

    constexpr int n_choose_k(const int n, const int k)
    {
        return k > n ? 0 : factorial(n) / factorial(n - k) / factorial(k);
    }

    std::vector<int> generate_columns_for_line(const std::size_t n)
    {
        const std::size_t columns_number = n + 1;

        std::vector<int> columns(columns_number);

        for(std::size_t k = 0; k < columns_number/2 + columns_number%2; ++k)
            columns[k] = columns[n-k] = n_choose_k(n,k);

        return columns;
    }

    std::vector<std::vector<int>> generate_rows(const std::size_t number_of_lines)
    {
        std::vector<std::vector<int>> pascals_triangle;

        for(std::size_t n = 0; n < number_of_lines; ++n)
            pascals_triangle.emplace_back(generate_columns_for_line(n));

        return pascals_triangle;
    }

}  // namespace pascals_triangle
