class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        int result = 0;
        
       
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
      
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();
            
            int row = pos.first;
            int col = pos.second;
            
          
            for (auto& dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    
                    
                    result += max(0, height - heightMap[newRow][newCol]);
                    
                 
                    int newHeight = max(heightMap[newRow][newCol], height);
                    pq.push({newHeight, {newRow, newCol}});
                }
            }
        }
        
        return result;
    }
};