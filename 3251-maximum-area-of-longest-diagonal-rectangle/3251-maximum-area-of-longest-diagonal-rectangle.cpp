class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = -1;   
        int maxArea = -1;   

        for (auto &rect : dimensions) {
            int l = rect[0], w = rect[1];
            int diag = l * l + w * w;
            int area = l * w;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag && area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
};
