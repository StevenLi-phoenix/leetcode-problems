// @leetcode id=1591 questionId=1696 slug=strange-printer-ii lang=cpp site=leetcode.com title="Strange Printer II"
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size(), n = targetGrid[0].size();
        int minR[61], maxR[61], minC[61], maxC[61];
        for (int c = 1; c <= 60; c++) {
            minR[c] = INT_MAX; maxR[c] = INT_MIN;
            minC[c] = INT_MAX; maxC[c] = INT_MIN;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = targetGrid[i][j];
                minR[c] = min(minR[c], i);
                maxR[c] = max(maxR[c], i);
                minC[c] = min(minC[c], j);
                maxC[c] = max(maxC[c], j);
            }
        }

        set<pair<int,int>> edges; // color a must be printed before color b: a->b (a is under b, i.e b covers a partially so b must come after a... actually edge means a depends on b being printed after: a must be UNDER b, so a printed first)
        vector<set<int>> adj(61); // adj[a] = set of colors that must be printed AFTER a (a is overlapped by them)
        vector<int> indeg(61, 0);
        set<pair<int,int>> edgeSet;

        for (int c = 1; c <= 60; c++) {
            if (minR[c] > maxR[c]) continue; // color not present
            for (int i = minR[c]; i <= maxR[c]; i++) {
                for (int j = minC[c]; j <= maxC[c]; j++) {
                    int other = targetGrid[i][j];
                    if (other != c) {
                        if (!edgeSet.count({c, other})) {
                            edgeSet.insert({c, other});
                            adj[c].insert(other);
                            indeg[other]++;
                        }
                    }
                }
            }
        }

        queue<int> q;
        vector<bool> present(61, false);
        int totalColors = 0;
        for (int c = 1; c <= 60; c++) {
            if (minR[c] <= maxR[c]) {
                present[c] = true;
                totalColors++;
                if (indeg[c] == 0) q.push(c);
            }
        }

        int processed = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        return processed == totalColors;
    }
};
