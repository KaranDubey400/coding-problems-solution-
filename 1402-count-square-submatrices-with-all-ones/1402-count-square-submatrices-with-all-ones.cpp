class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int total_count = 0;

       
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0];
            total_count += dp[i][0];
        }
        for (int j = 1; j < n; ++j) { 
            dp[0][j] = matrix[0][j];
            total_count += dp[0][j];
        }

       
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    total_count += dp[i][j];
                }
            }
        }
        return total_count;
    }
};