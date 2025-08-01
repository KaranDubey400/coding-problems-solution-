class Solution {
public:
    vector<vector<int>> generate(int numrows) {
        vector<vector<int>> result;
        result.push_back({1});

        for (int i = 1; i < numrows; ++i) {
            vector<int> prevrow = result.back();
            vector<int> newrow;

            newrow.push_back(1);

            for (int j = 1; j < prevrow.size(); ++j) {
                newrow.push_back(prevrow[j - 1] + prevrow[j]);
            }

            newrow.push_back(1);
            result.push_back(newrow);
        }

        return result;
    }
};