// @leetcode id=3218 questionId=3494 slug=minimum-cost-for-cutting-cake-i lang=cpp site=leetcode.com title="Minimum Cost for Cutting Cake I"
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int hi = 0, vi = 0;
        long long hCount = 1, vCount = 1;
        long long total = 0;

        while (hi < (int)horizontalCut.size() || vi < (int)verticalCut.size()) {
            bool takeH = vi >= (int)verticalCut.size() ||
                         (hi < (int)horizontalCut.size() && horizontalCut[hi] >= verticalCut[vi]);
            if (takeH) {
                total += (long long)horizontalCut[hi] * vCount;
                ++hCount;
                ++hi;
            } else {
                total += (long long)verticalCut[vi] * hCount;
                ++vCount;
                ++vi;
            }
        }
        return (int)total;
    }
};
