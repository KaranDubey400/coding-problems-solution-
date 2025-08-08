#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    
     
    double soupServings(int n) {
       
        if (n >= 4801) {
            return 1.0;
        }
     
        if (n == 0) {
            return 0.5;
        }

     
        int N = (n + 24) / 25;
        
       
        memo.resize(N + 1, std::vector<double>(N + 1, -1.0));
        
        return solve(N, N);
    }

private:
    
    std::vector<std::vector<double>> memo;

  
    double solve(int a, int b) {
     
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
       
        if (a <= 0) {
            return 1.0;
        }
       
        if (b <= 0) {
            return 0.0;
        }

        if (memo[a][b] > -0.5) { 
            return memo[a][b];
        }

       
        double prob = 0.25 * (solve(a - 4, b) +
                               solve(a - 3, b - 1) +
                               solve(a - 2, b - 2) +
                               solve(a - 1, b - 3));
    
        return memo[a][b] = prob;
    }
};