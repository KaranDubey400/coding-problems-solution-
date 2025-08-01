#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // Since nums[i] >= 1, product can't be less than 1 or 0
        
        int left = 0;
        int product = 1;
        int count = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                ++left;
            }
            count += right - left + 1;
        }
        
        return count;
    }
};