class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combo, int index) {
        if (target == 0) {
            result.push_back(combo);
            return;
        }
        if (target < 0) return;

        for (int i = index; i < candidates.size(); i++) {
            
            combo.push_back(candidates[i]);
            
            backtrack(candidates, target - candidates[i], result, combo, i);
           
            combo.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combo;
        backtrack(candidates, target, result, combo, 0);
        return result;
    }
};

