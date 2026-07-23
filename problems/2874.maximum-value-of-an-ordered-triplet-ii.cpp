// @leetcode id=2874 questionId=3152 slug=maximum-value-of-an-ordered-triplet-ii lang=cpp site=leetcode.com title="Maximum Value of an Ordered Triplet II"
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const long long NEG_INF = LLONG_MIN / 2;
        long long best = 0, maxNum = NEG_INF, maxDiff = NEG_INF;

        for (int x : nums) {
            if (maxDiff > NEG_INF) {
                best = max(best, maxDiff * x);
            }
            maxDiff = max(maxDiff, maxNum - x);
            maxNum = max(maxNum, (long long)x);
        }

        return best;
    }
};
