class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        
        for (int num : nums) {
            vector<int> temp = dp;
            for (int i = 0; i < 3; i++) {
                if (temp[i] != INT_MIN) {
                    dp[(i + num) % 3] = max(dp[(i + num) % 3], temp[i] + num);
                }
            }
        }
        
        return dp[0];
    }
};