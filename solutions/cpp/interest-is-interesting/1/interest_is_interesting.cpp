// interest_rate returns the interest rate for the provided balance.
[[nodiscard]] static constexpr double interest_rate(const double balance) {
    if (balance < 0)
        return 3.213;
    if (balance < 1'000)
        return 0.5;
    if (balance < 5'000)
        return 1.621;
    return 2.475;
}

// yearly_interest calculates the yearly interest for the provided balance.
[[nodiscard]] static constexpr double yearly_interest(const double balance) {
    return interest_rate(balance)/100 * balance;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
[[nodiscard]] static constexpr double annual_balance_update(const double balance) {
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
[[nodiscard]] static constexpr int years_until_desired_balance(const double balance, const double target_balance) {
    int years_until_desired_balance = 0;
    for (auto current = balance; current < target_balance; current = annual_balance_update(current))
        ++years_until_desired_balance;
    return years_until_desired_balance;
}