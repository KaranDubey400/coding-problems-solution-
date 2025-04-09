class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      
        for (int num : nums) {
            if (num < k) return -1;
        }

      
        set<int> s;
        for (int num : nums) {
            if (num > k) s.insert(num);
        }

        return s.size();
    }
};
