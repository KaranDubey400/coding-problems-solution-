#include <string>
#include <vector>

class Solution {
public:
    int possibleStringCount(std::string word) {
        if (word.empty()) {
            return 0; 
                     
        }

        int count = 1;
        int n = word.length();
        
        for (int i = 0; i < n; ) {
            char current_char = word[i];
            int j = i;
            while (j < n && word[j] == current_char) {
                j++;
            }
          
            int block_length = j - i;
            
            if (block_length > 1) {
              
                count += (block_length - 1);
            }
            i = j; 
        }
        
        return count;
    }
};