class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long T = (long long)num1 - k * (long long)num2;
            if (T < k) continue;  // too small
            if (__builtin_popcountll(T) <= k) return (int)k;
        }
        return -1;
    }
};
