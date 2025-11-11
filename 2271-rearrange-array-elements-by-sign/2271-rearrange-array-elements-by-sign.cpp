class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> karn;  
        queue<int> pq;   
        
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                karn.push(nums[i]); 
            } else {
                pq.push(nums[i]); 
            }
        }
        
      
        int k = 0; 
        while (!karn.empty()) {
            nums[k] = karn.front();  
            karn.pop();              
            k = k + 2;           
        }
        
        
        k = 1;
        while (!pq.empty()) {
            nums[k] = pq.front();   
            pq.pop();               
            k = k + 2;           
        }
        
        return nums;
    }
};