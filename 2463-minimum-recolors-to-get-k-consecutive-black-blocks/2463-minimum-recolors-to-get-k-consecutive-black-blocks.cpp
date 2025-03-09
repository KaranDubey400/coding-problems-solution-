class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int minOperations = INT_MAX; // Initialize to a large number
        
        // Count the number of 'W's in the first window of size k
        int currentRecolors = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                currentRecolors++; // Count 'W's in the initial window
            }
        }
        
        // Initialize minOperations with the first window's recolor count
        minOperations = currentRecolors;
        
        // Slide the window across the string
        for (int i = k; i < n; i++) {
            // Remove the effect of the block going out of the window
            if (blocks[i - k] == 'W') {
                currentRecolors--; // Reduce count if it was 'W'
            }
            // Add the effect of the new block coming into the window
            if (blocks[i] == 'W') {
                currentRecolors++; // Increase count if it is 'W'
            }
            
            // Update the minimum operations needed
            minOperations = min(minOperations, currentRecolors);
        }
        
        return minOperations; // Return the minimum operations found
    }
};
