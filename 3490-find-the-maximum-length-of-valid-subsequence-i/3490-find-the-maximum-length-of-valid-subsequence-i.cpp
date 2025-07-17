class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int count_even = 0;
        int count_odd = 0;

        for (int num : nums) {
            if (num % 2 == 0) {
                count_even++;
            } else {
                count_odd++;
            }
        }
        int max_same_parity_subsequence = max(count_even, count_odd);

      
        int alt_even_ending_len = 0;
        int alt_odd_ending_len = 0;  

        for (int num : nums) {
            if (num % 2 == 0) { 
             
                alt_even_ending_len = alt_odd_ending_len + 1;
              
            } else { 
                alt_odd_ending_len = alt_even_ending_len + 1;
            }
        }
        int max_alternating_subsequence = max(alt_even_ending_len, alt_odd_ending_len);

        return max(max_same_parity_subsequence, max_alternating_subsequence);
    }
};