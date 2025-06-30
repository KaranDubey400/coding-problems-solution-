#include <vector>
#include <unordered_map>
#include <algorithm> 

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
      
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxLength = 0;

        for (auto const& [num, count] : freqMap) {
        
            if (freqMap.count(num + 1)) {
               
                int currentLength = count + freqMap[num + 1];
              
                maxLength = std::max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};