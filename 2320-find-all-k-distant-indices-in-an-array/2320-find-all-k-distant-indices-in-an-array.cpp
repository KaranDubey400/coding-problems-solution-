#include <vector>
#include <cmath>
#include <algorithm> // For std::sort and std::unique if needed

class Solution {
public:
    std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
        std::vector<int> key_indices;
        // Step 1: Find all occurrences of key
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == key) {
                key_indices.push_back(j);
            }
        }

        std::vector<int> result;
        // Step 2 & 3: Iterate through all possible indices i and check the k-distant condition
        for (int i = 0; i < nums.size(); ++i) {
            bool is_k_distant = false;
            for (int j_val : key_indices) {
                if (std::abs(i - j_val) <= k) {
                    is_k_distant = true;
                    break; // Found at least one j, so i is a k-distant index
                }
            }
            if (is_k_distant) {
                result.push_back(i);
            }
        }
        
        // The problem statement says "Return a list of all k-distant indices sorted in increasing order."
        // Since we iterate 'i' in increasing order, 'result' will naturally be sorted.
        // We don't need to explicitly sort or remove duplicates because each 'i' is added only once.

        return result;
    }
};