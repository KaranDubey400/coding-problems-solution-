class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];  

        int prev2 = 0, prev1 = 0;  
        
        for (int money : nums) {
            int newRob = max(prev1, prev2 + money);  
            prev2 = prev1;
            prev1 = newRob;
        }
        
        return prev1;  
    }
};
