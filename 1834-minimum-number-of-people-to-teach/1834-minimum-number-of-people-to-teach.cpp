class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<unordered_set<int>> userLangs(m + 1);  // 1-based indexing
        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) {
                userLangs[i + 1].insert(lang);
            }
        }

        unordered_set<int> toTeach; // users who need teaching

        // Identify users in friendships that cannot communicate
        for (const auto& f : friendships) {
            int u = f[0];
            int v = f[1];
            bool canCommunicate = false;
            for (int lang : userLangs[u]) {
                if (userLangs[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                toTeach.insert(u);
                toTeach.insert(v);
            }
        }

        // Try each language to see which requires teaching the fewest people
        int minTeach = INT_MAX;
        for (int lang = 1; lang <= n; ++lang) {
            int count = 0;
            for (int user : toTeach) {
                if (!userLangs[user].count(lang)) {
                    count++;
                }
            }
            minTeach = min(minTeach, count);
        }

        return minTeach;
    }
};
