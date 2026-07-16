// @leetcode id=1620 questionId=1726 slug=coordinate-with-maximum-network-quality lang=cpp site=leetcode.com title="Coordinate With Maximum Network Quality"
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int bestQuality = -1;
        int bestX = 0, bestY = 0;

        for (int x = 0; x <= 50; x++) {
            for (int y = 0; y <= 50; y++) {
                int quality = 0;
                for (auto& t : towers) {
                    int dx = t[0] - x, dy = t[1] - y;
                    long long distSq = (long long)dx * dx + dy * dy;
                    if (distSq > (long long)radius * radius) continue;
                    double d = sqrt((double)distSq);
                    quality += (int)(t[2] / (1 + d));
                }
                if (quality > bestQuality) {
                    bestQuality = quality;
                    bestX = x;
                    bestY = y;
                }
            }
        }
        return {bestX, bestY};
    }
};
