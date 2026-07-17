// @leetcode id=391 questionId=391 slug=perfect-rectangle lang=cpp site=leetcode.com title="Perfect Rectangle"
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long minX = LLONG_MAX, minY = LLONG_MAX, maxX = LLONG_MIN, maxY = LLONG_MIN;
        long long totalArea = 0;
        set<pair<int,int>> corners;

        for (auto& r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            minX = min(minX, (long long)x1);
            minY = min(minY, (long long)y1);
            maxX = max(maxX, (long long)x2);
            maxY = max(maxY, (long long)y2);
            totalArea += (long long)(x2 - x1) * (y2 - y1);

            vector<pair<int,int>> pts = {{x1,y1},{x1,y2},{x2,y1},{x2,y2}};
            for (auto& p : pts) {
                if (corners.count(p)) corners.erase(p);
                else corners.insert(p);
            }
        }

        if (totalArea != (maxX - minX) * (maxY - minY)) return false;

        if (corners.size() != 4) return false;
        set<pair<int,int>> expected = {
            {(int)minX,(int)minY},{(int)minX,(int)maxY},{(int)maxX,(int)minY},{(int)maxX,(int)maxY}
        };

        return corners == expected;
    }
};
