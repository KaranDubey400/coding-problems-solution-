class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size(); 

      sort(nums.begin(), nums.end()); 
       vector<vector<int>> answer ; 

      for(int i =0 ; i < n ; i++){
        if(i>0 && nums[i]==nums[i-1])continue;
      int   j =i+1; 
      int   k = n-1; 
        while(j<k){
            int sum = nums[i]+ nums[j] + nums[k]; 
            if(sum <0 ){
               j++;
            } else if (sum > 0 ){
          k--; 
            } else {
                vector<int> ans = {nums[i], nums[j] , nums[k]}; 
                answer.push_back(ans); 
                j++; 
                k--; 
                while(j<k && nums[j-1]==nums[j]) j++; 
                while(j<k && nums[k]==nums[k+1])k--;     
            }
        }
     
      }
      return answer; 
    }    
};