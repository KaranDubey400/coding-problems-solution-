class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        vector<vector<int>>  ans (matrix.size(), vector<int>(matrix[0].size(),0)); 

        for(int i =0 ; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }

        for(int i =0 ; i < m ; i ++){
            for(int j =0 ; j < n; j++){
                matrix[i][j] = ans[i][j]; 
            }
        }
    }
};