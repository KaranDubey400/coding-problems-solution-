#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        int total_score = 0;
        
        std::string high_priority_pair = (x > y) ? "ab" : "ba";
        std::string low_priority_pair = (x > y) ? "ba" : "ab";
        int high_priority_score = std::max(x, y);
        int low_priority_score = std::min(x, y);

        std::string s_after_pass1;
        for (char c : s) {
            if (!s_after_pass1.empty() && s_after_pass1.back() == high_priority_pair[0] && c == high_priority_pair[1]) {
                s_after_pass1.pop_back();
                total_score += high_priority_score;
            } else {
                s_after_pass1.push_back(c);
            }
        }

        std::string s_after_pass2;
        for (char c : s_after_pass1) {
            if (!s_after_pass2.empty() && s_after_pass2.back() == low_priority_pair[0] && c == low_priority_pair[1]) {
                s_after_pass2.pop_back();
                total_score += low_priority_score;
            } else {
                s_after_pass2.push_back(c);
            }
        }

        return total_score;
    }
};