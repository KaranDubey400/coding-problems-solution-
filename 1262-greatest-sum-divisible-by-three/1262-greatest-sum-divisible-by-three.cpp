class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
     
        vector<int> rem1, rem2;
        
        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) rem1.push_back(num);
            if (num % 3 == 2) rem2.push_back(num);
        }
        
      
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());
        
        if (sum % 3 == 0) return sum;
        
        int result = 0;
        
        if (sum % 3 == 1) {
           
            if (!rem1.empty()) 
                result = max(result, sum - rem1[0]);
          
            if (rem2.size() >= 2) 
                result = max(result, sum - rem2[0] - rem2[1]);
        } 
        else if (sum % 3 == 2) {
           
            if (!rem2.empty()) 
                result = max(result, sum - rem2[0]);
          
            if (rem1.size() >= 2) 
                result = max(result, sum - rem1[0] - rem1[1]);
        }
        
        return result;
    }
};