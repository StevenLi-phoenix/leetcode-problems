// @leetcode id=3965 questionId=4092 slug=finish-time-of-tasks-i lang=cpp site=leetcode.com title="Finish Time of Tasks I"
class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> children(n);
        for (auto& e : edges) children[e[0]].push_back(e[1]);

        vector<long long> finish(n, -1);
        vector<int> order;
        order.reserve(n);
        vector<pair<int, int>> stk = {{0, 0}}; // node, child-index-to-process-next

        while (!stk.empty()) {
            auto& [u, idx] = stk.back();
            if (idx < (int)children[u].size()) {
                int v = children[u][idx];
                idx++;
                stk.push_back({v, 0});
            } else {
                order.push_back(u);
                stk.pop_back();
            }
        }

        for (int u : order) {
            if (children[u].empty()) {
                finish[u] = baseTime[u];
            } else {
                long long earliest = LLONG_MAX, latest = LLONG_MIN;
                for (int v : children[u]) {
                    earliest = min(earliest, finish[v]);
                    latest = max(latest, finish[v]);
                }
                long long ownDuration = (latest - earliest) + baseTime[u];
                finish[u] = latest + ownDuration;
            }
        }
        return finish[0];
    }
};
