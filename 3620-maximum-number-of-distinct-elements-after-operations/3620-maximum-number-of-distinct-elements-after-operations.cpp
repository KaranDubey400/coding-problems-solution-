#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        long long lastVal = -3000000000LL; 

        int distinctCount = 0;

        
        for (auto const& [val, count] : counts) {
            long long v = val; 
            int c = count;    

            for (int i = 0; i < c; ++i) {
             
                long long minPossible = v - k;
                
                long long requiredTarget = lastVal + 1;

             
                long long target = max(minPossible, requiredTarget);
                
                if (target <= v + k) {
                 
                    distinctCount++;
                  
                    lastVal = target;
                } else {
                   
                    break;
                }
            }
        }

        return distinctCount;
    }
};