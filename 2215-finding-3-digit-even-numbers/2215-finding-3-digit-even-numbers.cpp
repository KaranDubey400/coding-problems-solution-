#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> original_counts;
        for (int d : digits) {
            original_counts[d]++;
        }
        
        vector<int> result;
        
        for (int num = 100; num < 1000; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;
            
            unordered_map<int, int> num_counts;
            num_counts[d1]++;
            num_counts[d2]++;
            num_counts[d3]++;
            
            bool valid = true;
            for (auto& [digit, count] : num_counts) {
                if (original_counts[digit] < count) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(num);
            }
        }
        
      
        return result;
    }
};