#include "grade_school.h"

#include <algorithm>

template<typename T>
typename std::vector<T>::iterator insert_sorted(std::vector<T>& vector, const T& item)
{
    return vector.insert(std::upper_bound(vector.begin(), vector.end(), item), item);
}

namespace grade_school {    

    const std::map<int, std::vector<std::string>>& school::roster() const
    {
        return grades;
    }

    school& school::add(const std::string& student, const int grade)
    {
        insert_sorted(grades[grade], student);
        return *this;
    }

    std::vector<std::string> school::grade(const int grade) const
    {
        return grades.count(grade) != 0 ? grades.at(grade) : std::vector<std::string>{};
    }

}  // namespace grade_school
