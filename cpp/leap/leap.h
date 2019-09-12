#if !defined(LEAP_H)
#define LEAP_H

namespace leap {

    constexpr bool is_leap_year(const unsigned int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

}  // namespace leap

#endif // LEAP_H
