class Solution {
public:
    string clearStars(string s) {
        multiset<char> chars;
        vector<char> stack;

        for (char c : s) {
            if (c != '*') {
                stack.push_back(c);
                chars.insert(c);
            } else {
                // Remove the smallest character from the multiset
                char smallest = *chars.begin();
                chars.erase(chars.begin());

                // Remove one occurrence of smallest from the stack (rightmost one)
                for (int i = stack.size() - 1; i >= 0; --i) {
                    if (stack[i] == smallest) {
                        stack.erase(stack.begin() + i);
                        break;
                    }
                }
            }
        }

        return string(stack.begin(), stack.end());
    }
};
