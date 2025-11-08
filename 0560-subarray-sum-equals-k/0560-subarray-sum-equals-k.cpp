class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  
        
        int count = 0;
        int currentSum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
      
            if(prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }
          
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
};