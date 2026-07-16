// @leetcode id=3588 questionId=3868 slug=find-maximum-area-of-a-triangle lang=cpp site=leetcode.com title="Find Maximum Area of a Triangle"
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int globalMinX = INT_MAX, globalMaxX = INT_MIN;
        int globalMinY = INT_MAX, globalMaxY = INT_MIN;
        unordered_map<int, pair<int, int>> byX, byY; // value -> (minOther, maxOther)

        for (auto& c : coords) {
            int x = c[0], y = c[1];
            globalMinX = min(globalMinX, x);
            globalMaxX = max(globalMaxX, x);
            globalMinY = min(globalMinY, y);
            globalMaxY = max(globalMaxY, y);

            if (!byX.count(x)) byX[x] = {y, y};
            else { byX[x].first = min(byX[x].first, y); byX[x].second = max(byX[x].second, y); }

            if (!byY.count(y)) byY[y] = {x, x};
            else { byY[y].first = min(byY[y].first, x); byY[y].second = max(byY[y].second, x); }
        }

        long long best = -1;

        for (auto& [x0, minMaxY] : byX) {
            long long base = minMaxY.second - minMaxY.first;
            if (base == 0) continue;
            long long height = max((long long)globalMaxX - x0, (long long)x0 - globalMinX);
            if (height > 0) best = max(best, base * height);
        }

        for (auto& [y0, minMaxX] : byY) {
            long long base = minMaxX.second - minMaxX.first;
            if (base == 0) continue;
            long long height = max((long long)globalMaxY - y0, (long long)y0 - globalMinY);
            if (height > 0) best = max(best, base * height);
        }

        return best;
    }
};
