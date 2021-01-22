#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {

    class space_age
    {
        public:
            constexpr explicit space_age(const long long int age_in_seconds)
                : age_in_seconds{age_in_seconds}
            {}

            constexpr long long int seconds() const
            {
                return age_in_seconds;
            }

            constexpr double on_mercury() const
            {
                constexpr double mercury_orbital_period_in_seconds = 0.2408467;
                return on_earth() / mercury_orbital_period_in_seconds;
            }

            constexpr double on_venus() const
            {
                constexpr double venus_orbital_period_in_seconds = 0.61519726;
                return on_earth() / venus_orbital_period_in_seconds;
            }

            constexpr double on_earth() const
            {
                return seconds() / seconds_per_earth_year;
            }

            constexpr double on_mars() const
            {
                constexpr double mars_orbital_period_in_seconds = 1.8808158;
                return on_earth() / mars_orbital_period_in_seconds;
            }

            constexpr double on_jupiter() const
            {
                constexpr double jupiter_orbital_period_in_seconds = 11.862615;
                return on_earth() / jupiter_orbital_period_in_seconds;
            }

            constexpr double on_saturn() const
            {
                constexpr double saturn_orbital_period_in_seconds = 29.447498;
                return on_earth() / saturn_orbital_period_in_seconds;
            }

            constexpr double on_uranus() const
            {
                constexpr double uranus_orbital_period_in_seconds = 84.016846;
                return on_earth() / uranus_orbital_period_in_seconds;
            }

            constexpr double on_neptune() const
            {
                constexpr double neptune_orbital_period_in_seconds = 164.79132;
                return on_earth() / neptune_orbital_period_in_seconds;
            }

        private:
            static constexpr double seconds_per_earth_year = 365.25 * 24 * 3600;

            long long int age_in_seconds;
    };

}  // namespace space_age

#endif // SPACE_AGE_H
