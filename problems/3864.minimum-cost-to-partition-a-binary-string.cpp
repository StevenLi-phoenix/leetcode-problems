// @leetcode id=3864 questionId=4192 slug=minimum-cost-to-partition-a-binary-string lang=cpp site=leetcode.com title="Minimum Cost to Partition a Binary String"
class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int> prefixOnes(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixOnes[i + 1] = prefixOnes[i] + (s[i] == '1');
        }

        function<long long(int, int)> solve = [&](int l, int r) -> long long {
            int len = r - l;
            int ones = prefixOnes[r] - prefixOnes[l];
            long long whole = (ones == 0) ? (long long)flatCost
                                          : (long long)len * ones * encCost;
            if (len % 2 == 0 && len >= 2) {
                int mid = l + len / 2;
                whole = min(whole, solve(l, mid) + solve(mid, r));
            }
            return whole;
        };

        return solve(0, n);
    }
};
