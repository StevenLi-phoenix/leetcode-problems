// @leetcode id=2580 questionId=2651 slug=count-ways-to-group-overlapping-ranges lang=cpp site=leetcode.com title="Count Ways to Group Overlapping Ranges"
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        const long long MOD = 1e9 + 7;
        sort(ranges.begin(), ranges.end());

        int groups = 0;
        int curEnd = -1;
        for (auto& r : ranges) {
            if (r[0] > curEnd) {
                groups++;
                curEnd = r[1];
            } else {
                curEnd = max(curEnd, r[1]);
            }
        }

        long long result = 1;
        for (int i = 0; i < groups; i++) result = (result * 2) % MOD;
        return (int)result;
    }
};
