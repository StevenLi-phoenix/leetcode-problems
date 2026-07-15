// @leetcode id=464 questionId=464 slug=can-i-win lang=cpp site=leetcode.com title="Can I Win"
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        long long totalSum = (long long)maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (totalSum < desiredTotal) return false;

        memo.assign(1 << maxChoosableInteger, -1);
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }

private:
    vector<int> memo;

    bool dfs(int maxChoosable, int remaining, int used) {
        if (memo[used] != -1) return memo[used];

        for (int i = 1; i <= maxChoosable; i++) {
            int bit = 1 << (i - 1);
            if (used & bit) continue;
            if (i >= remaining || !dfs(maxChoosable, remaining - i, used | bit)) {
                memo[used] = 1;
                return true;
            }
        }
        memo[used] = 0;
        return false;
    }
};
