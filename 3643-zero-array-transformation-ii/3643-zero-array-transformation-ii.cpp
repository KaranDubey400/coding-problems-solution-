class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size();
        
        // Check if nums is already all zeros
        bool allZero = true;
        for (int i = 0; i < n && allZero; i++) {
            if (nums[i] != 0) allZero = false;
        }
        if (allZero) return 0;

        // Check if all queries suffice
        if (!canFormZeroArray(nums, queries, right)) return -1;

        // Binary Search
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (canFormZeroArray(nums, queries, middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }

private:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);
        
        // Process first k queries
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val; // Avoid out-of-bounds
        }
        
        // Check if decrements suffice
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < nums[i]) return false;
        }
        return true;
    }
};