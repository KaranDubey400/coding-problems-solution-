#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;
        
        for (int num : nums1) {
            if (num == 0) {
                zero1++;
            } else {
                sum1 += num;
            }
        }
        
        for (int num : nums2) {
            if (num == 0) {
                zero2++;
            } else {
                sum2 += num;
            }
        }
        
       
        long long min_sum1 = sum1 + zero1;
        long long min_sum2 = sum2 + zero2;
        
        if (zero1 == 0 && zero2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        } else if (zero1 == 0) {
            if (sum1 < min_sum2) {
                return -1;
            } else {
                return sum1;
            }
        } else if (zero2 == 0) {
            if (sum2 < min_sum1) {
                return -1;
            } else {
                return sum2;
            }
        } else {
            
            return max(min_sum1, min_sum2);
        }
    }
};