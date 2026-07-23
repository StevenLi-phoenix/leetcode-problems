// @leetcode id=3000 questionId=3251 slug=maximum-area-of-longest-diagonal-rectangle lang=cpp site=leetcode.com title="Maximum Area of Longest Diagonal Rectangle"
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long bestDiagSq = -1;
        int bestArea = 0;

        for (auto& d : dimensions) {
            long long l = d[0], w = d[1];
            long long diagSq = l * l + w * w;
            long long area = l * w;

            if (diagSq > bestDiagSq || (diagSq == bestDiagSq && area > bestArea)) {
                bestDiagSq = diagSq;
                bestArea = area;
            }
        }
        return bestArea;
    }
};
