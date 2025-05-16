#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && words[i].size() == words[j].size()) {
                    if (hammingDistance(words[i], words[j]) == 1) {
                        if (dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            prev[i] = j;
                        }
                    }
                }
            }
        }
        
        int max_len = *max_element(dp.begin(), dp.end());
        int current = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == max_len) {
                current = i;
                break;
            }
        }
        
        vector<string> result;
        while (current != -1) {
            result.push_back(words[current]);
            current = prev[current];
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    int hammingDistance(const string& a, const string& b) {
        int distance = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                distance++;
            }
        }
        return distance;
    }
};