// @leetcode id=1465 questionId=1575 slug=maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts lang=cpp site=leetcode.com title="Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts"
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const long long MOD = 1e9 + 7;
        long long maxGap = maxGapFn(h, horizontalCuts);
        long long maxGapV = maxGapFn(w, verticalCuts);
        return (int)((maxGap * maxGapV) % MOD);
    }

private:
    long long maxGapFn(int limit, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        long long maxGap = cuts[0];
        for (size_t i = 1; i < cuts.size(); i++) {
            maxGap = max(maxGap, (long long)cuts[i] - cuts[i - 1]);
        }
        maxGap = max(maxGap, (long long)limit - cuts.back());
        return maxGap;
    }
};
