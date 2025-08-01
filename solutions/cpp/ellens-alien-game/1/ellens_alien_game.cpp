namespace targets {
    struct Alien
    {
            [[nodiscard]] constexpr unsigned int get_health() const
            {
                return health;
            }

            constexpr bool hit()
            {
                if (is_alive())
                    --health;
                return true;
            }

            [[nodiscard]] constexpr bool is_alive() const
            {
                return health != 0;
            }

            constexpr bool teleport(const int x, const int y)
            {
                x_coordinate = x;
                y_coordinate = y;
                return true;
            }

            [[nodiscard]] constexpr bool collision_detection(const Alien& other) const
            {
                return x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate;
            }
    
            int x_coordinate;
            int y_coordinate;
            unsigned int health = 3;
    };
}  // namespace targets