class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        
        for (int i = 1; i < n; i++) {
            int tempMax = maxEndingHere;
            
            maxEndingHere = max({nums[i], maxEndingHere * nums[i], minEndingHere * nums[i]});
            minEndingHere = min({nums[i], tempMax * nums[i], minEndingHere * nums[i]});
            
            result = max(result, maxEndingHere);
        }
        
        return result;
    }
};