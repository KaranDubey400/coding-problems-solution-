class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> current;
        findSubsets(nums, 0, current, allSubsets);
        return allSubsets;
    }

private:
    void findSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& allSubsets) {
        allSubsets.push_back(current);
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            findSubsets(nums, i + 1, current, allSubsets);
            current.pop_back();
        }
    }
};