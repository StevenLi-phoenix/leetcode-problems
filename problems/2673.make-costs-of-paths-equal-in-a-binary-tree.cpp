// @leetcode id=2673 questionId=2780 slug=make-costs-of-paths-equal-in-a-binary-tree lang=cpp site=leetcode.com title="Make Costs of Paths Equal in a Binary Tree"
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<long long> subtreeMax(n + 1, 0);
        for (int i = 1; i <= n; i++) subtreeMax[i] = cost[i - 1];

        long long ans = 0;
        for (int i = n / 2; i >= 1; i--) {
            long long left = subtreeMax[2 * i];
            long long right = subtreeMax[2 * i + 1];
            ans += llabs(left - right);
            subtreeMax[i] = cost[i - 1] + max(left, right);
        }
        return (int)ans;
    }
};
