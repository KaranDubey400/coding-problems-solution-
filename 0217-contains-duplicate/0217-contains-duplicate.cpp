class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>seen ; 

        for(auto each : nums){
            if(seen.find(each) != seen.end()){
                return true ; 
            }

            seen.insert(each); 
        }

        return false; 
    }
};