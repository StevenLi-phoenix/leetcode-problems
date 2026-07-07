// @leetcode id=1203 questionId=1309 slug=sort-items-by-groups-respecting-dependencies lang=cpp site=leetcode.com title="Sort Items by Groups Respecting Dependencies"
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int totalGroups = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) group[i] = totalGroups++;
        }

        vector<vector<int>> itemAdj(n);
        vector<int> itemIndeg(n, 0);
        vector<vector<int>> groupAdj(totalGroups);
        vector<int> groupIndeg(totalGroups, 0);
        set<pair<int, int>> groupEdgesSeen;

        for (int i = 0; i < n; ++i) {
            for (int b : beforeItems[i]) {
                itemAdj[b].push_back(i);
                ++itemIndeg[i];

                if (group[b] != group[i]) {
                    auto edge = make_pair(group[b], group[i]);
                    if (groupEdgesSeen.insert(edge).second) {
                        groupAdj[group[b]].push_back(group[i]);
                        ++groupIndeg[group[i]];
                    }
                }
            }
        }

        auto topoSort = [](vector<vector<int>>& adj, vector<int>& indeg) -> vector<int> {
            int sz = indeg.size();
            vector<int> order;
            queue<int> q;
            for (int i = 0; i < sz; ++i) {
                if (indeg[i] == 0) q.push(i);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                order.push_back(u);
                for (int v : adj[u]) {
                    if (--indeg[v] == 0) q.push(v);
                }
            }
            return order;
        };

        vector<int> itemOrder = topoSort(itemAdj, itemIndeg);
        if ((int)itemOrder.size() < n) return {};

        vector<int> groupOrder = topoSort(groupAdj, groupIndeg);
        if ((int)groupOrder.size() < totalGroups) return {};

        vector<int> groupPos(totalGroups);
        for (int i = 0; i < (int)groupOrder.size(); ++i) groupPos[groupOrder[i]] = i;

        stable_sort(itemOrder.begin(), itemOrder.end(), [&](int a, int b) {
            return groupPos[group[a]] < groupPos[group[b]];
        });

        return itemOrder;
    }
};
