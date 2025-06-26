#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int res = 0;
        int val = 0;
        int bit = 0; 
        
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                res++;
                bit++;
            } else {
              
                if (bit < 31 && (val + (1 << bit)) <= k) {
                    val += (1 << bit);
                    res++;
                    bit++;
                }
            }
        }
        return res;
    }
};