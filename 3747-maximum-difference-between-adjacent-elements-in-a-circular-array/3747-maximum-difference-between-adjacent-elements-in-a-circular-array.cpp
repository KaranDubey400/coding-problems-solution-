class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n; // handles circular case
            int diff = abs(nums[i] - nums[next]);
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};
