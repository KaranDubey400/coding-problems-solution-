class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        
        for(int i = 0; i < numRows; i++) {
            long long ans = 1;
            vector<int> temp;
            temp.push_back(1); 
            
            for(int j = 1; j <= i; j++) {
                ans = ans * (i - j + 1);
                ans = ans / j;
                temp.push_back(ans);
            }
            
            answer.push_back(temp);
        }
        
        return answer;
    }
};