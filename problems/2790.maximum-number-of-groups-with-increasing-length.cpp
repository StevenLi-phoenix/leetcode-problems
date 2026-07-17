// @leetcode id=2790 questionId=2919 slug=maximum-number-of-groups-with-increasing-length lang=cpp site=leetcode.com title="Maximum Number of Groups With Increasing Length"
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());

        long long total = 0, need = 1;
        int groups = 0;

        for (int x : usageLimits) {
            total += x;
            if (total >= need) {
                groups++;
                total -= need;
                need++;
            }
        }

        return groups;
    }
};
