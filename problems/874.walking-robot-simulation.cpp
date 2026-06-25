// @leetcode id=874 questionId=906 slug=walking-robot-simulation lang=cpp site=leetcode.com title="Walking Robot Simulation"
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for (auto& o : obstacles) obs.insert({o[0], o[1]});
        int x = 0, y = 0, d = 0, ans = 0;
        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
        for (int c : commands) {
            if (c == -2) d = (d + 3) % 4;
            else if (c == -1) d = (d + 1) % 4;
            else {
                for (int i = 0; i < c; i++) {
                    if (obs.count({x + dx[d], y + dy[d]})) break;
                    x += dx[d]; y += dy[d];
                }
                ans = max(ans, x*x + y*y);
            }
        }
        return ans;
    }
};
