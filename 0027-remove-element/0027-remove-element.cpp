class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; 

        for (int i = 0; i < nums.size(); ++i) { 
            if (nums[i] != val) {
                nums[k] = nums[i]; // Place non-val element at current k position
                k++;             // Move write pointer forward
            }
        }
        return k; // k is the new length
    }
};