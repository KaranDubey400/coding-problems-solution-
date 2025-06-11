class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans;

        for (int num : nums){
            mp[num]++;
        }

        for (auto p : mp){
            if (p.second >= 2){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};