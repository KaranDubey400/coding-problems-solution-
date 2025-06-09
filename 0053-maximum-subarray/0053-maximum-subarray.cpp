class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        int maxsum = INT_MIN;
        int currentsum = 0 ; 

        for(int i =0 ; i < n ; i++){
            currentsum += nums[i]; 

            if(currentsum >maxsum ){
                maxsum = currentsum ; 
            }

            if(currentsum <0 ){
                currentsum =0; 
            }
        }

        return maxsum ; 
    }
};