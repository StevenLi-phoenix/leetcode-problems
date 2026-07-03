// @leetcode id=2274 questionId=2355 slug=maximum-consecutive-floors-without-special-floors lang=cpp site=leetcode.com title="Maximum Consecutive Floors Without Special Floors"
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int maxGap = special[0] - bottom;
        for (int i = 1; i < (int)special.size(); ++i) {
            maxGap = max(maxGap, special[i] - special[i - 1] - 1);
        }
        maxGap = max(maxGap, top - special.back());
        return maxGap;
    }
};
