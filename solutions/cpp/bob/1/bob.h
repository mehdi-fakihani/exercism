#if !defined(BOB_H)
#define BOB_H

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

#include <iostream>

namespace bob {
    
    [[nodiscard]] std::string hey(std::string_view message)
    {
        const auto begin = std::cbegin(message);
        const auto end   = std::find_if(std::crbegin(message), std::crend(message), [](const char c){ return !std::isspace(c); }).base();

        if (message.empty() || std::all_of(begin, end, [](const char c){ return std::isspace(c); }))
            return "Fine. Be that way!";
        
        const bool is_question = *(end - 1) == '?';
        bool at_least_one_alpha_character = false;
        const bool is_yelling =
            std::all_of(
                begin,
                end,
                [&at_least_one_alpha_character](const char c)
                {
                    const bool is_alpha = std::isalpha(c);
                    at_least_one_alpha_character |= is_alpha;
                    return !is_alpha || std::isupper(c);
                }
            )
            &&
            at_least_one_alpha_character;

        if (is_yelling && is_question)
            return "Calm down, I know what I'm doing!";
        else if (is_question)
            return "Sure.";
        else if (is_yelling)
            return "Whoa, chill out!";
        else
            return "Whatever.";
    }
}  // namespace bob

#endif // BOB_H