// @leetcode id=3857 questionId=4024 slug=minimum-cost-to-split-into-ones lang=cpp site=leetcode.com title="Minimum Cost to Split into Ones"
class Solution {
public:
    int minCost(int n) {
        // Splitting n into n ones always costs the same total regardless
        // of order: each pair of final "1" units contributes exactly once
        // to some a*b product along the way, giving C(n,2) = n*(n-1)/2.
        return (int)((long long)n * (n - 1) / 2);
    }
};
