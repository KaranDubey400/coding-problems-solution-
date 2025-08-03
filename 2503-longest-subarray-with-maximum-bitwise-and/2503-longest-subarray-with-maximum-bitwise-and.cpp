#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        
        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
            }
        }
      
        int max_len = 0;
        int current_len = 0;
        for (int num : nums) {
            if (num == max_val) {
                current_len++;
            } else {
                max_len = std::max(max_len, current_len);
                current_len = 0;
            }
        }

        
        max_len = std::max(max_len, current_len);

        return max_len;
    }
};