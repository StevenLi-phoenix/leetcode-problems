// @leetcode id=1936 questionId=2066 slug=add-minimum-number-of-rungs lang=cpp site=leetcode.com title="Add Minimum Number of Rungs"
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int res = 0;
        int prev = 0;
        for (int r : rungs) {
            int gap = r - prev;
            if (gap > dist) {
                res += (gap - 1) / dist;
            }
            prev = r;
        }
        return res;
    }
};
