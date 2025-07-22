class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for (char c : s) {
            if (res.length() < 2) {
                res += c;
            } else {
                if (!(res.back() == c && res[res.length() - 2] == c)) {
                    res += c;
                }
            }
        }
        return res;
    }
};
