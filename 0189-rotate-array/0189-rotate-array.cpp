#include <vector>
#include <algorithm> // For reverse function

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n
        
        // Approach 1: Using extra space (corrected version of your approach)
        vector<int> temp(n);
        
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        
        nums = temp;
    }
};