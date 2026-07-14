// @leetcode id=1953 questionId=2084 slug=maximum-number-of-weeks-for-which-you-can-work lang=cpp site=leetcode.com title="Maximum Number of Weeks for Which You Can Work"
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0, maxVal = 0;
        for (int m : milestones) {
            total += m;
            maxVal = max(maxVal, (long long)m);
        }
        long long rest = total - maxVal;
        if (maxVal > rest + 1) return 2 * rest + 1;
        return total;
    }
};
