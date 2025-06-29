#include <vector>
#include <cmath> 
#include <algorithm> 

class Solution {
public:
    int maxAdjacentDistance(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            
            return 0;
        }

        int max_diff = 0;

    
        for (int i = 0; i < n - 1; ++i) {
            max_diff = std::max(max_diff, std::abs(nums[i] - nums[i+1]));
        }
        
        max_diff = std::max(max_diff, std::abs(nums[n-1] - nums[0]));

        return max_diff;
    }
};