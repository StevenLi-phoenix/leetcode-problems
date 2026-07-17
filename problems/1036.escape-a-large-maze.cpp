// @leetcode id=1036 questionId=1106 slug=escape-a-large-maze lang=cpp site=leetcode.com title="Escape a Large Maze"
class Solution {
public:
    long long limit;

    long long encode(long long x, long long y) { return x * 1000000LL + y; }

    bool bfs(vector<vector<int>>& blocked, vector<int>& start, vector<int>& end) {
        unordered_set<long long> blockedSet;
        for (auto& b : blocked) blockedSet.insert(encode(b[0], b[1]));

        unordered_set<long long> visited;
        long long sx = start[0], sy = start[1];
        long long ex = end[0], ey = end[1];

        visited.insert(encode(sx, sy));
        queue<pair<long long,long long>> q;
        q.push({sx, sy});

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == ex && y == ey) return true;
            if ((long long)visited.size() > limit) return true;

            for (int d = 0; d < 4; d++) {
                long long nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= 1000000 || ny < 0 || ny >= 1000000) continue;
                long long code = encode(nx, ny);
                if (blockedSet.count(code) || visited.count(code)) continue;
                visited.insert(code);
                q.push({nx, ny});
            }
        }

        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        long long b = blocked.size();
        limit = b * (b - 1) / 2;

        return bfs(blocked, source, target) && bfs(blocked, target, source);
    }
};
