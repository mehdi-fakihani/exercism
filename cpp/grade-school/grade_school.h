#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <string>
#include <vector>

namespace grade_school {

    class school
    {
        public:
            const std::map<int, std::vector<std::string>>& roster() const;
            school& add(const std::string& student, const int grade);
            std::vector<std::string> grade(const int grade) const;
        private:
            std::map<int, std::vector<std::string>> grades;
    };

}  // namespace grade_school

#endif // GRADE_SCHOOL_H
