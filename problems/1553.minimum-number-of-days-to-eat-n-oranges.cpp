// @leetcode id=1553 questionId=1676 slug=minimum-number-of-days-to-eat-n-oranges lang=cpp site=leetcode.com title="Minimum Number of Days to Eat N Oranges"
class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int n) -> int {
            if (n == 0) return 0;
            if (n == 1) return 1;

            if (memo.count(n)) return memo[n];

            int result = min(n % 2 + 1 + dp(n / 2), n % 3 + 1 + dp(n / 3));

            return memo[n] = result;
        };

        return dp(n);
    }
};
