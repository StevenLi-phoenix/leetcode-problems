// @leetcode id=1033 questionId=1103 slug=moving-stones-until-consecutive lang=cpp site=leetcode.com title="Moving Stones Until Consecutive"
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a, b, c});
        int z = max({a, b, c});
        int y = a + b + c - x - z;

        int gap1 = y - x - 1;
        int gap2 = z - y - 1;

        int mn;
        if (gap1 == 0 && gap2 == 0) mn = 0;
        else if (gap1 <= 1 || gap2 <= 1) mn = 1;
        else mn = 2;

        int mx = gap1 + gap2;

        return {mn, mx};
    }
};
