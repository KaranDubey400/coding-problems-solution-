class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        
        int max_prefix = nums[0]; 
        
        
        vector<int> max_suffix(n, 0);
        max_suffix[n - 1] = nums[n - 1];

        
        for (int k = n - 2; k >= 0; k--) {
            max_suffix[k] = max(max_suffix[k + 1], nums[k]);
        }

    
        for (int j = 1; j < n - 1; j++) {
           
            long long max_diff = max_prefix - nums[j];

            
            if (max_diff > 0) {
                result = max(result, max_diff * 1LL * max_suffix[j + 1]);
            }

           
            max_prefix = max(max_prefix, nums[j]);
        }

        return result;
    }
};
