class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dst, unordered_set<string>& visited) {
        if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) return -1.0;
        if (src == dst) return 1.0;
        visited.insert(src);

        for (auto& neighbor : graph[src]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;
            if (!visited.count(nextNode)) {
                double res = dfs(nextNode, dst, visited);
                if (res != -1.0) return res * weight;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

      
        vector<double> result;
        for (auto& query : queries) {
            unordered_set<string> visited;
            double res = dfs(query[0], query[1], visited);
            result.push_back(res);
        }
        return result;
    }
};
