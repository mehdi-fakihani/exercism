#include "queen_attack.h"

#include <cmath>
#include <sstream>
#include <stdexcept>

namespace queen_attack {

    chess_board::chess_board(const std::pair<int,int>& white, const std::pair<int,int>& black) :
        _white{white},
        _black{black}
    {
        if(white == black)
            throw std::domain_error{"Both of the queens can't have the same position"};
    }

    chess_board::operator std::string() const
    {
        std::pair<int,int> cell;
        std::ostringstream output{};

        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                cell = {i,j};

                if(_white == cell)
                    output << 'W';
                else if (_black == cell)
                    output << 'B';
                else
                    output << '_';

                output << (j == 7 ? '\n' : ' ');
            }
        }

        return output.str();
    }

    bool chess_board::can_attack() const
    {
        return _white.first == _black.first ||
               _white.second == _black.second ||
               std::abs(_white.first - _black.first) == std::abs(_white.second - _black.second);
    }

    std::pair<int,int> chess_board::white() const
    {
        return _white;
    }

    std::pair<int,int> chess_board::black() const
    {
        return _black;
    }

}  // namespace queen_attack
