#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() < 1) {
            return "";
        }

        int start = 0;
        int maxLength = 1; 

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        };

        // Iterate through each character as a potential center
        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindromes (e.g., "aba")
            expandAroundCenter(i, i);

            // Case 2: Even length palindromes (e.g., "abba")
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};