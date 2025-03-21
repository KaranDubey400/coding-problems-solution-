#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        
        // Step 1: Build graph and calculate in-degree for each recipe
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size(); // Number of ingredients required
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]); // ing → recipe dependency
            }
        }
        
        // Step 2: Process initial supplies
        queue<string> q;
        for (const string& s : supplies) {
            q.push(s);
        }
        
        // Step 3: Topological Sorting (BFS)
        vector<string> result;
        while (!q.empty()) {
            string item = q.front();
            q.pop();
            
            if (inDegree.count(item)) { // If it's a recipe
                result.push_back(item);
            }
            
            for (const string& dependent : graph[item]) {
                if (--inDegree[dependent] == 0) { // All ingredients available
                    q.push(dependent);
                }
            }
        }
        
        return result;
    }
};

