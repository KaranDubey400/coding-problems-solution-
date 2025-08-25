class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();

        // map: diagonal index -> elements
        unordered_map<int, vector<int>> diag;

        // Step 1: group elements by (i+j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag[i + j].push_back(mat[i][j]);
            }
        }

        // Step 2: build the result
        vector<int> ans;
        for (int d = 0; d <= m + n - 2; d++) {
            if (d % 2 == 0) {
                // reverse order for snake effect
                for (auto it = diag[d].rbegin(); it != diag[d].rend(); it++) {
                    ans.push_back(*it);
                }
            } else {
                for (int x : diag[d]) ans.push_back(x);
            }
        }
        return ans;
    }
};
