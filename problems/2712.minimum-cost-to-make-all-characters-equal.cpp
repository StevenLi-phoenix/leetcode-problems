// @leetcode id=2712 questionId=2817 slug=minimum-cost-to-make-all-characters-equal lang=cpp site=leetcode.com title="Minimum Cost to Make All Characters Equal"
class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        long long total = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                total += min(i, n - i);
            }
        }
        return total;
    }
};
