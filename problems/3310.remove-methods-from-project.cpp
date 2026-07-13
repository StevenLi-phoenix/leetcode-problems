// @leetcode id=3310 questionId=3561 slug=remove-methods-from-project lang=cpp site=leetcode.com title="Remove Methods From Project"
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& e : invocations) adj[e[0]].push_back(e[1]);

        vector<char> suspicious(n, 0);
        suspicious[k] = 1;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = 1;
                    q.push(v);
                }
            }
        }

        for (auto& e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                // an outside method invokes into the suspicious group; abort removal
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) if (!suspicious[i]) result.push_back(i);
        return result;
    }
};
