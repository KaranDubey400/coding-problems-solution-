class Solution {
public:
    vector<int> getRow(int N) {
        vector<int> row;
        
        long long val = 1;
        row.push_back(val);
        
      for(int i = 1; i < N+1; i++){
        val = val * (N - i +1)  / i; 
        row.push_back(val);
      }
        
        return row;
    }
};