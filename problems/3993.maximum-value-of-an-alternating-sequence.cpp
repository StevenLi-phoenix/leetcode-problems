// @leetcode id=3993 questionId=4364 slug=maximum-value-of-an-alternating-sequence lang=cpp site=leetcode.com title="Maximum Value of an Alternating Sequence"
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long S = s, M = m;
        long long iMax = n / 2;
        long long upValue = (iMax == 0) ? S : S + iMax * (M - 1) + 1;

        long long jMax = (n - 1) / 2;
        long long downValue = S + jMax * (M - 1);

        return max(upValue, downValue);
    }
};
