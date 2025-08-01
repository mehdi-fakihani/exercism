#if !defined(HEXADECIMAL_H)
#define HEXADECIMAL_H

#include <cstdlib>

namespace hexadecimal {
    [[nodiscard]] unsigned long int convert(const char* hexadecimal_integer)
    {
        constexpr auto base = 16;
        char* end;
        const auto parsed_value = std::strtoul(hexadecimal_integer, &end, base);
        return *end == '\0' ? parsed_value : 0;
    }
}  // namespace hexadecimal

#endif // HEXADECIMAL_H