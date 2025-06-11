class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num(nums1.begin(), nums1.end()) ; 
        unordered_set<int> result; 

        for(auto n : nums2){
            if(num.count(n)){
                result.insert(n); 
            }
        }

        return vector<int>(result.begin(), result.end()); 
    }
};