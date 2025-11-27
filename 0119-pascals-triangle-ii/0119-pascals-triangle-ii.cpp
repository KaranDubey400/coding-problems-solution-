class Solution {
public:
    vector<int> getRow(int N) {
        vector<int> row;
        
        long long val = 1;
        row.push_back(val);
        
      
        for (int k = 1; k <= N; k++) {
            val = val * (N - k + 1) / k;
            row.push_back(val);
        }
        
        return row;
    }
};