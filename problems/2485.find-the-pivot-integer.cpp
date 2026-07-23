// @leetcode id=2485 questionId=2571 slug=find-the-pivot-integer lang=cpp site=leetcode.com title="Find the Pivot Integer"
class Solution {
public:
    int pivotInteger(int n) {
        long long target = (long long)n * (n + 1) / 2;
        int x = (int)round(sqrt((double)target));
        for (int cand = max(1, x - 2); cand <= x + 2; cand++) {
            if ((long long)cand * cand == target) return cand;
        }
        return -1;
    }
};
