#include <vector>
#include <iostream>

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return 0; // Not enough elements to form a hill or valley
        }

        std::vector<int> compressed_nums;
        if (!nums.empty()) {
            compressed_nums.push_back(nums[0]);
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] != nums[i-1]) {
                    compressed_nums.push_back(nums[i]);
                }
            }
        }
        
        if (compressed_nums.size() < 3) {
            return 0; // After compression, still not enough elements
        }

        int count = 0;
        for (int i = 1; i < compressed_nums.size() - 1; ++i) {
            // Check for hill
            if (compressed_nums[i] > compressed_nums[i-1] && compressed_nums[i] > compressed_nums[i+1]) {
                count++;
            } 
            // Check for valley
            else if (compressed_nums[i] < compressed_nums[i-1] && compressed_nums[i] < compressed_nums[i+1]) {
                count++;
            }
        }
        return count;
    }
};