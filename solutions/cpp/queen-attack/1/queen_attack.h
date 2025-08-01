#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <string>
#include <utility>

namespace queen_attack {

    class chess_board
    {
        public:
            explicit chess_board(const std::pair<int,int>& white = {0,3}, const std::pair<int,int>& black =  {7,3});

            operator std::string() const;

            bool can_attack() const;

            std::pair<int,int> white() const;
            std::pair<int,int> black() const;

        private:
            std::pair<int,int> _white;
            std::pair<int,int> _black;
    };

}  // namespace queen_attack

#endif // QUEEN_ATTACK_H
