class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        // Sort points by x-coordinate ascending, then y-coordinate descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
              
                if (points[i][1] >= points[j][1]) {
                    bool empty = true;
                  
                    for (int k = i + 1; k < j; ++k) {
                      
                        if (points[k][0] >= points[i][0] && points[k][0] <= points[j][0] && 
                            points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
                            empty = false;
                            break;
                        }
                    }
                    if (empty) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};