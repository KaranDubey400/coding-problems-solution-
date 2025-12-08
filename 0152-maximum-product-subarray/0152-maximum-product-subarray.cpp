class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxProduct = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
         
            int temp = currentMax;
            
         
            currentMax = max({nums[i], nums[i] * currentMax, nums[i] * currentMin});
            currentMin = min({nums[i], nums[i] * temp, nums[i] * currentMin});
            
          
            maxProduct = max(maxProduct, currentMax);
        }
        
        return maxProduct;
    }
};