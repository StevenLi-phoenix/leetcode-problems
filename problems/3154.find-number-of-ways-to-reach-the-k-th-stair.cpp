// @leetcode id=3154 questionId=3414 slug=find-number-of-ways-to-reach-the-k-th-stair lang=cpp site=leetcode.com title="Find Number of Ways to Reach the K-th Stair"
class Solution {
public:
    unordered_map<long long, long long> memo;

    long long dfs(long long i, int jump, bool canDown, long long k) {
        if (i > k + 1) return 0;

        long long key = (i * 100LL + jump * 2 + (canDown ? 1 : 0));
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        long long res = (i == k) ? 1 : 0;
        if (canDown && i > 0) res += dfs(i - 1, jump, false, k);
        res += dfs(i + (1LL << jump), jump + 1, true, k);

        memo[key] = res;
        return res;
    }

    int waysToReachStair(int k) {
        return (int)dfs(1, 0, true, k);
    }
};
