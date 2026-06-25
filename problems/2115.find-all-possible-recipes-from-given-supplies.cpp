// @leetcode id=2115 questionId=2220 slug=find-all-possible-recipes-from-given-supplies lang=cpp site=leetcode.com title="Find All Possible Recipes from Given Supplies"
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Build graph: ingredient -> list of recipes that need it
        // in-degree: count of unsatisfied ingredients for each recipe
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        set<string> recipeSet(recipes.begin(), recipes.end());
        
        for (int i = 0; i < (int)recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }
        
        // BFS starting from supplies
        queue<string> q;
        for (const string& s : supplies) q.push(s);
        
        vector<string> result;
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            
            if (recipeSet.count(cur)) result.push_back(cur);
            
            for (const string& next : graph[cur]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return result;
    }
};
