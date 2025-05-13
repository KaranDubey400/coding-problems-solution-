#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        for (int i = 0; i < t; ++i) {
            vector<long long> new_counts(26, 0);
            for (int j = 0; j < 26; ++j) {
                if (j != 25) {
                    new_counts[j + 1] = (new_counts[j + 1] + counts[j]) % MOD;
                } else {
                    new_counts[0] = (new_counts[0] + counts[j]) % MOD;
                    new_counts[1] = (new_counts[1] + counts[j]) % MOD;
                }
            }
            counts = new_counts;
        }
        
        long long total = 0;
        for (long long num : counts) {
            total = (total + num) % MOD;
        }
        return (int)total;
    }
};