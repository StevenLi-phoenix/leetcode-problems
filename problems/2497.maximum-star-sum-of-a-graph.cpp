// @leetcode id=2497 questionId=2590 slug=maximum-star-sum-of-a-graph lang=cpp site=leetcode.com title="Maximum Star Sum of a Graph"
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(vals[e[1]]);
            adj[e[1]].push_back(vals[e[0]]);
        }

        int best = INT_MIN;
        for (int i = 0; i < n; i++) {
            vector<int> neighbors = adj[i];
            sort(neighbors.begin(), neighbors.end(), greater<int>());
            long long sum = vals[i];
            for (int j = 0; j < k && j < (int)neighbors.size(); j++) {
                if (neighbors[j] <= 0) break;
                sum += neighbors[j];
            }
            best = max(best, (int)sum);
        }
        return best;
    }
};
