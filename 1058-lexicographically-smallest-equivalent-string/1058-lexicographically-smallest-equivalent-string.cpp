class Solution {
public:
    int parent[26];

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            // always keep the smaller char as parent for lex order
            if (px < py)
                parent[py] = px;
            else
                parent[px] = py;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // init parent
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        // build union
        for (int i = 0; i < s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        // build result
        string result;
        for (char c : baseStr) {
            result += (char)(find(c - 'a') + 'a');
        }

        return result;
    }
};
