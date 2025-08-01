#include <regex>
#include <string>
#include <sstream>

namespace log_line {
    static const std::regex log_line_pattern{
        "^\\[(INFO|WARNING|ERROR)\\]: ((?:\\w\\s?)+)$"
    };
    
    [[nodiscard]] std::string message(const std::string& line) {
        std::smatch match;
        if (!std::regex_match(line, match,log_line_pattern))
            return {};
        return match[2].str();
    }

    [[nodiscard]] std::string log_level(const std::string& line) {
        std::smatch match;
        if (!std::regex_match(line, match,log_line_pattern))
            return {};
        return match[1].str();
    }

    [[nodiscard]] std::string reformat(const std::string& line) {
        std::smatch match;
        if (!std::regex_match(line, match,log_line_pattern))
            return {};

        std::ostringstream result;
        result << match[2].str() << " (" << match[1].str() << ")";
        return result.str();
    }
}
