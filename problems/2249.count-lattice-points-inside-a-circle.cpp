// @leetcode id=2249 questionId=2332 slug=count-lattice-points-inside-a-circle lang=cpp site=leetcode.com title="Count Lattice Points Inside a Circle"
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int maxCoord = 0;
        for (auto& c : circles) maxCoord = max(maxCoord, c[0] + c[2]);
        maxCoord = max(maxCoord, 200);

        int count = 0;
        for (int x = 0; x <= maxCoord; x++) {
            for (int y = 0; y <= maxCoord; y++) {
                for (auto& c : circles) {
                    int dx = x - c[0], dy = y - c[1];
                    if (dx * dx + dy * dy <= c[2] * c[2]) {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};
