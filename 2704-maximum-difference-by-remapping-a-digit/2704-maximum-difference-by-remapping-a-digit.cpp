#include <string>
#include <algorithm>

class Solution {
public:
    int minMaxDifference(int num) {
        std::string s_num = std::to_string(num);

    
        std::string max_s = s_num;
        char digit_to_replace_for_max = ' ';
        for (char c : max_s) {
            if (c != '9') {
                digit_to_replace_for_max = c;
                break;
            }
        }
        if (digit_to_replace_for_max != ' ') { 
            std::replace(max_s.begin(), max_s.end(), digit_to_replace_for_max, '9');
        }
        long long max_val = std::stoll(max_s); 

        
        std::string min_s = s_num;
        char digit_to_replace_for_min = min_s[0]; 
        std::replace(min_s.begin(), min_s.end(), digit_to_replace_for_min, '0');
        long long min_val = std::stoll(min_s);

        return static_cast<int>(max_val - min_val);
    }
};