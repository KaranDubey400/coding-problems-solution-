class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(37, 0); // Max sum = 9+9+9+9 = 36 for n <= 10^4
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            count[sum]++;
            maxSize = max(maxSize, count[sum]);
        }

        int result = 0;
        for (int c : count) {
            if (c == maxSize) result++;
        }

        return result;
    }
};

