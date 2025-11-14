class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()){
            return 0; 
        }
        sort(nums.begin(), nums.end()); 

        int smaller = INT_MIN; 
        int count = 0 ; 
        int longest = 1; 

        for(int i =0; i < nums.size(); i++){
if(nums[i]-1==smaller){
    count += 1;
    smaller = nums[i];
}  else if (nums[i] !=smaller){
      count =1; 
      smaller = nums[i]; 
     } 
     longest = max(longest, count); 


        }

        return longest; 
    }
};