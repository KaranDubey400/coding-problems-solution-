#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        std::string prefix = strs[0];

        for (size_t i = 1; i < strs.size(); ++i) {
            const std::string& current_str = strs[i];

            while (current_str.find(prefix) != 0) {
                if (prefix.empty()) {
                    return "";
                }
                prefix = prefix.substr(0, prefix.length() - 1);
            }
        }

        return prefix;
    }
};
