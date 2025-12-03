class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        
        for (int i = 0; i < words.size(); i++) {
         
            if (i == 0) {
                result.push_back(words[i]);
                continue;
            }
            
      
            vector<int> freq1(26, 0), freq2(26, 0);
            for (char c : words[i-1]) freq1[c - 'a']++;
            for (char c : words[i]) freq2[c - 'a']++;
            
        
            bool isAnagram = true;
            for (int j = 0; j < 26; j++) {
                if (freq1[j] != freq2[j]) {
                    isAnagram = false;
                    break;
                }
            }
            
            if (!isAnagram) {
                result.push_back(words[i]);
            }
        }
        
        return result;
    }
};