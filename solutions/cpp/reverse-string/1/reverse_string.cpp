#include "reverse_string.h"

#include <algorithm>

namespace reverse_string {

    std::string reverse_string(const std::string &string)
    {
        std::string copy {string};
        std::reverse_copy(string.begin(),string.end(),copy.begin());
        return copy;
    }

}  // namespace reverse_string
