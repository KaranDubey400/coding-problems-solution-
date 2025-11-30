class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for(int num : nums) {
            total_sum += num;
        }
        
        int rem = total_sum % p;
        if(rem == 0) return 0; 
        
       
        
        unordered_map<int, int> mp;
        mp[0] = -1; 
        
        long long prefix_sum = 0;
        int min_len = nums.size(); 
        
        for(int i = 0; i < nums.size(); i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            
           
            int target = (prefix_sum - rem + p) % p;
            
            if(mp.find(target) != mp.end()) {
           
                int subarray_len = i - mp[target];
                min_len = min(min_len, subarray_len);
            }
            
            mp[prefix_sum] = i;
        }
        
        return (min_len == nums.size()) ? -1 : min_len;
    }
};