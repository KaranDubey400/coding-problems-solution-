class Solution {
public:
   
        int maxProduct(vector<int> &arr) {
    int n = arr.size();
  
    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++) {
        int mul = 1;
      
        // traversing in current subarray
        for (int j = i; j < n; j++) {
          	mul *= arr[j];
          
            // updating result every time
            // to keep track of the maximum product
            result = max(result, mul);
        }
    }
    return result;

    }
};