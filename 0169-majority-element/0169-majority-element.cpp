class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> karn; 
  int n = nums.size(); 

        for(int i=0; i < n ; i++){
             karn[nums[i]]++; 
        }

        int p = n/2; 

       for(auto each: karn){
        if(each.second > p ){
            return each.first;
        }
       }
     return 0 ; 
    }
};