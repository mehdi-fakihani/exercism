[[noreturn]] inline void unreachable()
{
#if defined(_MSC_VER) && !defined(__clang__) // MSVC
    __assume(false);
#else // GCC, Clang
    __builtin_unreachable();
#endif
}

namespace hellmath {

    enum struct AccountStatus
    {
        troll,
        guest,
        user,
        mod
    };

    enum struct Action
    {
        read,
        write,
        remove
    };

    [[nodiscard]] constexpr bool display_post(const AccountStatus poster, const AccountStatus viewer)
    {
        switch(poster)
        {
            case AccountStatus::troll:
                return poster == viewer;
            default:
                return true;
        }
    }

    [[nodiscard]] constexpr bool permission_check(const Action action, const AccountStatus status)
    {
        switch(status)
        {
            case AccountStatus::guest:
                return action == Action::read;
            case AccountStatus::user:
            case AccountStatus::troll:
                return action == Action::read || action == Action::write;
            case AccountStatus::mod:
                return true;
            default:
                unreachable();
        }
    }

    [[nodiscard]] constexpr bool valid_player_combination(const AccountStatus first_player, const AccountStatus second_player)
    {
        return
            (first_player != AccountStatus::guest && first_player != AccountStatus::troll && second_player != AccountStatus::guest && second_player != AccountStatus::guest && second_player != AccountStatus::troll) || 
            (first_player == AccountStatus::troll && second_player == AccountStatus::troll);
    }

    [[nodiscard]] constexpr bool has_priority(const AccountStatus first_player, const AccountStatus second_player)
    {
        return (static_cast<int>(first_player) - static_cast<int>(second_player)) > 0;
    }
}  // namespace hellmath