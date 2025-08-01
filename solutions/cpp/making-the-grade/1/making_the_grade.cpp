#include <algorithm>
#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
[[nodiscard]] static std::vector<int> round_down_scores(const std::vector<double>& student_scores) {
    return {
        std::begin(student_scores),
        std::end(student_scores),
    };
}


// Count the number of failing students out of the group provided.
[[nodiscard]] static int count_failed_students(const std::vector<int>& student_scores) { 
    return std::count_if(
        std::begin(student_scores),
        std::end(student_scores),
        [](const auto student_score){
            static constexpr unsigned int required_score = 40;
            return student_score <= required_score;
        }
    );
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
[[nodiscard]] static std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    student_scores.erase(
        std::remove_if(
            std::begin(student_scores),
            std::end(student_scores),
            [threshold = std::move(threshold)](const auto student_score){ return student_score < threshold; }
        ),
        std::end(student_scores)
    );
    return student_scores;
}

// Create a list of grade thresholds based on the provided highest grade.
[[nodiscard]] static std::array<int, 4> letter_grades(int highest_score) {
    static constexpr int failing_threshold = 40;
    const double delta = (highest_score - failing_threshold) / 4.0;
    return {
        failing_threshold + 1,
        failing_threshold + 1 + static_cast<int>(delta),
        failing_threshold + 1 + static_cast<int>(2 * delta),
        failing_threshold + 1 + static_cast<int>(3 * delta),
    };
}

// Organize the student's rank, name, and grade information in ascending order.
[[nodiscard]] static std::vector<std::string> student_ranking(const std::vector<int>& student_scores, const std::vector<std::string>& student_names) {
    std::vector<std::string> student_ranking;
    student_ranking.reserve(student_scores.size());
    for (std::size_t i = 0; i < student_scores.size() && i < student_names.size(); ++i)
    {
        student_ranking.emplace_back(
            std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i])
        );
    }
    return student_ranking;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
[[nodiscard]] static std::string perfect_score(const std::vector<int>& student_scores, const std::vector<std::string>& student_names) {
    static constexpr int perfect_score = 100;
    for (std::size_t i = 0; i < student_scores.size(); ++i)
        if (student_scores[i] == perfect_score)
            return student_names[i];
    return {};
}
