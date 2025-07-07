class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];

        // Check if it can form a triangle
        if (a + b <= c || a + c <= b || b + c <= a) {
            return "none";
        }

        // All sides equal
        if (a == b && b == c) {
            return "equilateral";
        }

        // Exactly two sides equal
        if (a == b || b == c || a == c) {
            return "isosceles";
        }

        // All sides different
        return "scalene";
    }
};
