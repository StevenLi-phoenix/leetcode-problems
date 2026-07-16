// @leetcode id=1743 questionId=1866 slug=restore-the-array-from-adjacent-pairs lang=cpp site=leetcode.com title="Restore the Array From Adjacent Pairs"
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        int start = 0;
        for (auto& [key, neighbors] : adj) {
            if (neighbors.size() == 1) {
                start = key;
                break;
            }
        }

        int n = adj.size();
        vector<int> result;
        result.reserve(n);
        result.push_back(start);
        int prev = INT_MIN;
        int cur = start;
        for (int i = 1; i < n; i++) {
            auto& neighbors = adj[cur];
            int next = (neighbors[0] != prev) ? neighbors[0] : neighbors[1];
            result.push_back(next);
            prev = cur;
            cur = next;
        }
        return result;
    }
};
