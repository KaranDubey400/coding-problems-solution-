#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int create_max_num(int n) {
        std::string s = std::to_string(n);
        char digit_to_replace = ' ';
        for (char c : s) {
            if (c != '9') {
                digit_to_replace = c;
                break;
            }
        }

        if (digit_to_replace == ' ') { // All digits are already '9'
            return n;
        }

        std::string a_str = s;
        for (char &c : a_str) {
            if (c == digit_to_replace) {
                c = '9';
            }
        }
        return std::stoi(a_str);
    }

    int create_min_num(int n) {
        std::string s = std::to_string(n);
        std::string b_str = s;

        if (s[0] != '1') {
            char digit_to_replace = s[0];
            for (char &c : b_str) {
                if (c == digit_to_replace) {
                    c = '1';
                }
            }
        } else { // First digit is '1'
            char digit_to_replace = ' ';
            for (size_t i = 1; i < s.length(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    digit_to_replace = s[i];
                    break;
                }
            }

            if (digit_to_replace == ' ') { // No digit other than '0' or '1' found after the first '1'
                return n; // Cannot make it smaller
            }

            for (char &c : b_str) {
                if (c == digit_to_replace) {
                    c = '0';
                }
            }
        }
        return std::stoi(b_str);
    }

    int maxDiff(int num) {
        int a = create_max_num(num);
        int b = create_min_num(num);
        return a - b;
    }
};