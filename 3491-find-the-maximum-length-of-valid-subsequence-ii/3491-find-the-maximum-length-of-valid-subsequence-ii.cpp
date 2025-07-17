#include <vector>
#include <numeric> 
#include <algorithm> 

class Solution {
public:
    int maximumLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        int overall_max_len = 0;

      
        for (int R = 0; R < k; ++R) {
            std::vector<int> dp_for_current_R(k, 0);

          
            for (int num : nums) {
                int current_num_rem = num % k;

         
                int required_prev_rem = (R - current_num_rem + k) % k;

                int potential_new_len = dp_for_current_R[required_prev_rem] + 1;
                
           
                dp_for_current_R[current_num_rem] = std::max(dp_for_current_R[current_num_rem], potential_new_len);
                
               
                overall_max_len = std::max(overall_max_len, dp_for_current_R[current_num_rem]);
            }
        }
        
        

        return overall_max_len;
    }
};