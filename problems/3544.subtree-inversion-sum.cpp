// @leetcode id=3544 questionId=3858 slug=subtree-inversion-sum lang=cpp site=leetcode.com title="Subtree Inversion Sum"
class Solution {
public:
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        // dp[node][d][s] = best achievable sum of subtree(node), where
        // s is the ambient sign entering node (0 -> +1, 1 -> -1) and d is
        // the distance since the nearest inverted ancestor (capped at k;
        // d==k means far enough to invert here too, or none above yet).
        // When inversion is allowed the optimal choice can depend on the
        // ambient sign (invert to flip back to whichever sign is better),
        // so the sign must be tracked explicitly rather than assumed.
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);
        vector<char> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[order[i]]].push_back(order[i]);

        // dp[node][d][s], flattened as dp[node][d*2+s]
        vector<vector<long long>> dp(n, vector<long long>((k + 1) * 2, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            int u = order[idx];
            vector<long long> childSum((k + 1) * 2, 0); // [cap*2+s], cap in 1..k
            for (int c : children[u]) {
                for (int cap = 1; cap <= k; cap++) {
                    childSum[cap * 2 + 0] += dp[c][cap * 2 + 0];
                    childSum[cap * 2 + 1] += dp[c][cap * 2 + 1];
                }
            }

            for (int s = 0; s < 2; s++) {
                long long sign = (s == 0) ? 1 : -1;
                for (int d = 0; d < k; d++) {
                    int cap = min(d + 1, k);
                    dp[u][d * 2 + s] = sign * nums[u] + childSum[cap * 2 + s];
                }
                long long optionA = sign * nums[u] + childSum[k * 2 + s];
                long long optionB = -sign * nums[u] + childSum[1 * 2 + (1 - s)];
                dp[u][k * 2 + s] = max(optionA, optionB);
            }
        }

        return dp[0][k * 2 + 0];
    }
};
