#include <string>
#include <vector>
#include <algorithm> // For std::max and std::min
#include <limits>    // For std::numeric_limits

class Solution {
public:
    int maxDifference(std::string s) {
        // Use a vector to store frequencies of 'a' through 'z'
        // Index 0 for 'a', 1 for 'b', ..., 25 for 'z'
        std::vector<int> freq(26, 0);

        // Count character frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }

        int max_odd_freq = std::numeric_limits<int>::min(); // Initialize with smallest possible int value
        int min_even_freq = std::numeric_limits<int>::max(); // Initialize with largest possible int value

        // Iterate through frequencies to find max_odd_freq and min_even_freq
        for (int i = 0; i < 26; ++i) {
            int current_freq = freq[i];
            if (current_freq > 0) { // Only consider characters present in the string
                if (current_freq % 2 != 0) { // Odd frequency
                    max_odd_freq = std::max(max_odd_freq, current_freq);
                } else { // Even frequency
                    min_even_freq = std::min(min_even_freq, current_freq);
                }
            }
        }

        // According to constraints, at least one odd and one even frequency character will exist.
        // So, max_odd_freq and min_even_freq will be updated from their initial sentinels.
        return max_odd_freq - min_even_freq;
    }
};