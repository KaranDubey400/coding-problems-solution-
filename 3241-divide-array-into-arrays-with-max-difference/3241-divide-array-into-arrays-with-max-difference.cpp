class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i += 3) {
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];

            // Check max diff in the triplet
            if (c - a <= k) {
                result.push_back({a, b, c});
            } else {
                return {}; // invalid group found
            }
        }

        return result;
    }
};
