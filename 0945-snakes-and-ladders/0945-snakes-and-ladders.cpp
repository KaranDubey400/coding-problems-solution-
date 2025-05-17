#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattened(n * n + 1); // 1-based indexing
        bool leftToRight = true;
        int index = 1;
        
        // Flatten the board into a 1D array, accounting for Boustrophedon style
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    flattened[index++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    flattened[index++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }
        
        queue<int> q;
        vector<int> dist(n * n + 1, -1);
        q.push(1);
        dist[1] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == n * n) {
                return dist[curr];
            }
            
            for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
                int destination = flattened[next] == -1 ? next : flattened[next];
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        
        return -1;
    }
};