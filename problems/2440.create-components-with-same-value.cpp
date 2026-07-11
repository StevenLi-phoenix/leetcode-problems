// @leetcode id=2440 questionId=2531 slug=create-components-with-same-value lang=cpp site=leetcode.com title="Create Components With Same Value"
class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int total = 0, maxVal = 0;
        for (int x : nums) { total += x; maxVal = max(maxVal, x); }
        if (n == 1) return 0;

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS from 0 to get a parent-before-child order (avoids recursion
        // depth issues on a path-shaped tree with n up to 2*10^4).
        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> queue = {0};
        visited[0] = true;
        for (int qi = 0; qi < (int)queue.size(); qi++) {
            int u = queue[qi];
            order.push_back(u);
            for (int v : adj[u])
                if (!visited[v]) { visited[v] = true; parent[v] = u; queue.push_back(v); }
        }

        // Try each divisor of total as the target component sum, smallest
        // first (i.e. most components, most edges cut) via bottom-up merge.
        auto feasible = [&](int target, int& cuts) {
            vector<int> sum(nums.begin(), nums.end());
            cuts = 0;
            for (int i = n - 1; i >= 0; i--) {
                int u = order[i];
                if (sum[u] > target) return false;
                if (u == 0) return sum[u] == target;
                if (sum[u] == target) cuts++;
                else sum[parent[u]] += sum[u];
            }
            return true;
        };

        for (int target = maxVal; target <= total; target++) {
            if (total % target != 0) continue;
            int cuts;
            if (feasible(target, cuts)) return cuts;
        }
        return 0;
    }
};
