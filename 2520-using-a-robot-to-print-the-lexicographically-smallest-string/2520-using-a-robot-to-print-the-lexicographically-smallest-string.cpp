class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuffix(n);
        minSuffix[n - 1] = s[n - 1];

        // Fill minSuffix[i] = min char from s[i..end]
        for (int i = n - 2; i >= 0; --i) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        string res = "";
        stack<char> t;

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            // While stack top is <= smallest remaining char, pop
            while (!t.empty() && t.top() <= minSuffix[i + 1 >= n ? n - 1 : i + 1]) {
                res += t.top();
                t.pop();
            }
        }

        // Pop the rest
        while (!t.empty()) {
            res += t.top();
            t.pop();
        }

        return res;
    }
};
