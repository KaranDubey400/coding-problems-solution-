class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        
        // Starting from each digit root (1 to 9), do a DFS traversal
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, result);
        }
        
        return result;
    }
    
    // Helper function to perform DFS and add numbers in lexicographical order
    void dfs(int current, int n, vector<int>& result) {
        if (current > n) return;
        
        // Add the current number to the result
        result.push_back(current);
        
        // Try to append digits (0 to 9) to the current number
        for (int i = 0; i <= 9; i++) {
            int next = current * 10 + i;
            if (next > n) break;  // Stop if the number exceeds n
            dfs(next, n, result); // Recursive DFS call for the next number
        }
    }
};
