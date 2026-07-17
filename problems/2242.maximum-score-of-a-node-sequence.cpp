// @leetcode id=2242 questionId=2353 slug=maximum-score-of-a-node-sequence lang=cpp site=leetcode.com title="Maximum Score of a Node Sequence"
class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
                return scores[a] > scores[b];
            });
            if (adj[i].size() > 3) adj[i].resize(3);
        }

        int best = -1;
        for (auto& e : edges) {
            int b = e[0], c = e[1];
            for (int a : adj[b]) {
                if (a == c) continue;
                for (int d : adj[c]) {
                    if (d == b || d == a) continue;
                    int score = scores[a] + scores[b] + scores[c] + scores[d];
                    best = max(best, score);
                }
            }
        }

        return best;
    }
};
