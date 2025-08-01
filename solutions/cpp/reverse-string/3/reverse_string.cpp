#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(const std::string& string)
    {
        std::string copy {string.rbegin(), string.rend()};
        return copy;
    }

}  // namespace reverse_string
