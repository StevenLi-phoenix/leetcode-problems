// @leetcode id=851 questionId=881 slug=loud-and-rich lang=cpp site=leetcode.com title="Loud and Rich"
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> answer;
    vector<int>* quietPtr;

    int dfs(int x) {
        if (answer[x] != -1) return answer[x];
        int best = x;
        for (int next : adj[x]) {
            int candidate = dfs(next);
            if ((*quietPtr)[candidate] < (*quietPtr)[best]) best = candidate;
        }
        answer[x] = best;
        return best;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        adj.assign(n, {});
        for (auto& r : richer) {
            adj[r[1]].push_back(r[0]);
        }
        answer.assign(n, -1);
        quietPtr = &quiet;
        for (int i = 0; i < n; i++) dfs(i);
        return answer;
    }
};
