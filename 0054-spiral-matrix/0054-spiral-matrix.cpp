class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int totalElements = m * n;
        int count = 0;
        
        int startRow = 0, startCol = 0;
        int endRow = m - 1, endCol = n - 1;
        
        while (count < totalElements) {
           
            for (int i = startCol; i <= endCol && count < totalElements; i++) {
                result.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            
           
            for (int i = startRow; i <= endRow && count < totalElements; i++) {
                result.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            
           
            for (int i = endCol; i >= startCol && count < totalElements; i--) {
                result.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            
            
            for (int i = endRow; i >= startRow && count < totalElements; i--) {
                result.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        
        return result;
    }
};