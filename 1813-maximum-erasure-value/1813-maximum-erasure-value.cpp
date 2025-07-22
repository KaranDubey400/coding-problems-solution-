class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> uniqueElements;
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (uniqueElements.count(nums[right])) {
                uniqueElements.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
            uniqueElements.insert(nums[right]);
            currentSum += nums[right];
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
