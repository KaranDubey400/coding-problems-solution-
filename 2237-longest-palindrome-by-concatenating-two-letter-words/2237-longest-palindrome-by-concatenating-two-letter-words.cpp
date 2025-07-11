class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        int length = 0;
        bool usedCenter = false;

        for (auto& [word, count] : freq) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                // Symmetric word like "gg", "cc"
                int pairs = count / 2;
                length += pairs * 4;
                freq[word] -= pairs * 2;

                if (!usedCenter && freq[word] > 0) {
                    length += 2;
                    usedCenter = true;
                }
            } else if (freq.find(rev) != freq.end()) {
                int pairCount = min(freq[word], freq[rev]);
                length += pairCount * 4;
                freq[word] -= pairCount;
                freq[rev] -= pairCount;
            }
        }

        return length;
    }
};
