// @leetcode id=1376 questionId=1492 slug=time-needed-to-inform-all-employees lang=cpp site=leetcode.com title="Time Needed to Inform All Employees"
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) children[manager[i]].push_back(i);
        }

        int best = 0;
        queue<pair<int, int>> bfs;
        bfs.push({headID, 0});
        while (!bfs.empty()) {
            auto [id, time] = bfs.front(); bfs.pop();
            best = max(best, time);
            for (int child : children[id]) {
                bfs.push({child, time + informTime[id]});
            }
        }
        return best;
    }
};
