class Solution {
public:
    string intToRoman(int num) {
        // Define Roman numeral values and their symbols in descending order
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";

        // Iterate through the romanMap
        for (auto const& [value, symbol] : romanMap) {
            // While the number is greater than or equal to the current value
            while (num >= value) {
                // Append the symbol to the result string
                result += symbol;
                // Subtract the value from the number
                num -= value;
            }
        }

        return result;
    }
};