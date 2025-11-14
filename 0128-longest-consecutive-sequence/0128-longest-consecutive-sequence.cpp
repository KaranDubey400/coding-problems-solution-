class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0; 
        }
        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 

        int smallest = INT_MIN;
        int longest = 1; 
        int count = 0 ;

        for(int i =0 ; i < nums.size(); i++){
            if(nums[i]-1 == smallest){
                count +=1; 
                smallest = nums[i]; 
            } else if (nums[i] != smallest){
                smallest = nums[i]; 
                count =1; 
            }

            longest = max(longest, count); 
        }

        return longest; 
    }
};