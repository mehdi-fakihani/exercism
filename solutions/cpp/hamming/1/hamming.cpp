#include "hamming.h"

namespace hamming {

    unsigned int compute(const std::string& a, const std::string& b)
    {
        if(a.size() != b.size())
            throw std::domain_error("The strings don't have the same size !");

        unsigned int result = 0;
        for(size_t i = 0; i < a.size(); i++)
            if(a[i] != b[i])
                result++;

        return result;
    }

}  // namespace hamming
