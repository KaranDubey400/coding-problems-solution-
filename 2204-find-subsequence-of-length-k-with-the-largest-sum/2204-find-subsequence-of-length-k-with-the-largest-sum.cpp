#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.emplace_back(nums[i], i);
        }
        
        // Sort in descending order of value to get the top k elements
        sort(indexedNums.begin(), indexedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Take the top k elements and sort them by their original indices
        vector<pair<int, int>> topK(indexedNums.begin(), indexedNums.begin() + k);
        sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        vector<int> result;
        for (const auto& p : topK) {
            result.push_back(p.first);
        }
        
        return result;
    }
};