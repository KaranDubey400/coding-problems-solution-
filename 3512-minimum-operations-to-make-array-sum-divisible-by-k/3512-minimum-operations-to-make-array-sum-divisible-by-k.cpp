class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalSum = 0;
      
        for (int num : nums) {
            totalSum += num;
        }
        
     
        return totalSum % k;
    }
};