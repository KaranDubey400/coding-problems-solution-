class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }


    
    int countVowelSubstrings(string word) {
        int n = word.length();
        int count = 0;

        
            unordered_set<char> vowels;
        for (int i = 0; i < n; i++) {
            if (!isVowel(word[i])) continue;

            for (int j = i; j < n && isVowel(word[j]); j++) {
                vowels.insert(word[j]);
                if (vowels.size() == 5) {
                    count++;
                }
            }

            vowels.clear(); 
        }
        
        return count;
    }
};
