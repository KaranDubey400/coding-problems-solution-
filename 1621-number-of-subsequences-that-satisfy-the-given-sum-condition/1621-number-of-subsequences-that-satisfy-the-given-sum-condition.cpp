#include <vector>
#include <algorithm>

class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        int mod = 1e9 + 7;

        
        std::vector<long long> pows(n);
        pows[0] = 1;
        for (int i = 1; i < n; ++i) {
            pows[i] = (pows[i - 1] * 2) % mod;
        }

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
              
                count = (count + pows[right - left]) % mod;
                left++;
            } else {
              
                right--;
            }
        }

        return count;
    }
};