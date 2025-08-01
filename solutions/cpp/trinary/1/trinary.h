#if !defined(TRINARY_H)
#define TRINARY_H

#include <string>

namespace trinary {
    [[nodiscard]] unsigned int to_decimal(const std::string& trinary)
    {
        try
        {
            return std::stoi(trinary, nullptr, 3);
        }
        catch(const std::exception&)
        {
            return 0;
        }
    }
}  // namespace trinary

#endif // TRINARY_H