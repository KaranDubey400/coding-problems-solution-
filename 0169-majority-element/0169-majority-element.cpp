#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
      
        unordered_map<int, int> karn; 
        for(auto each : nums){
            karn[each]++;
        }

        int n = nums.size();
        for (auto const& [val, count] : karn) { 
            if (count > n / 2) {
                return val;
            }
        }
        return -1; // Should not reach here if a majority element always exists as per problem constraints
    }
};