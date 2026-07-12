// @leetcode id=2145 questionId=2249 slug=count-the-hidden-sequences lang=cpp site=leetcode.com title="Count the Hidden Sequences"
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // The prefix-sum sequence (starting at 0) fixes the shape; the
        // number of valid starting values equals (upper-lower+1) minus the
        // range spanned by the prefix sums (their max - min).
        long long prefix = 0, minP = 0, maxP = 0;
        for (int d : differences) {
            prefix += d;
            minP = min(minP, prefix);
            maxP = max(maxP, prefix);
        }
        long long range = maxP - minP;
        long long count = (long long)(upper - lower + 1) - range;
        return (int)max(count, 0LL);
    }
};
