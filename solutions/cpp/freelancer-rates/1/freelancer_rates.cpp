#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
[[nodiscard]] static constexpr double daily_rate(const double hourly_rate) {
    constexpr auto hours_per_day = 8;
    return hours_per_day * hourly_rate;
}

// apply_discount calculates the price after a discount
[[nodiscard]] static constexpr double apply_discount(const double before_discount, const double discount) {
    return (1 - discount/100) * before_discount;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
[[nodiscard]] static constexpr int monthly_rate(const double hourly_rate, const double discount) {
    constexpr auto days_per_month = 22;
    return std::ceil(apply_discount(days_per_month * daily_rate(hourly_rate), discount));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
[[nodiscard]] static constexpr int days_in_budget(const int budget, const double hourly_rate, const double discount) {
    return std::floor(budget / apply_discount(daily_rate(hourly_rate), discount));
}