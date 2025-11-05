class Solution {
public:
    bool check(vector<int>& nums) {
        int dips  = 0 ; 

        for(int i =0 ; i < nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                dips++; 
            }

            if(dips>1){
                return false ; 
            }
        }

        if(nums.back() > nums.front()){
            dips++;
        }

        return dips<=1; 
    }
};