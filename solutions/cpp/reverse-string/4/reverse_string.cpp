#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(const std::string& string)
    {
        return {string.rbegin(), string.rend()};
    }

}  // namespace reverse_string
