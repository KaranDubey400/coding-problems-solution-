class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff = -1;
        int min_element = nums[0];
        
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] > min_element) {
                int current_diff = nums[j] - min_element;
                if (current_diff > max_diff) {
                    max_diff = current_diff;
                }
            } else {
                min_element = nums[j];
            }
        }
        
        return max_diff;
    }
};