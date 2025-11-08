class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number = 0 ; 

        for(auto each : nums){
            number = number^each; 
        }

        return number ; 
    }
};