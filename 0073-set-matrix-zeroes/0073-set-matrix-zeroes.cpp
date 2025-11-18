class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<bool> rowZero(row, false);
        vector<bool> colZero(col, false);
        
        // First pass: mark which rows and columns need to be zeroed
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }
        
        // Second pass: set zeros based on markers
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(rowZero[i] || colZero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};