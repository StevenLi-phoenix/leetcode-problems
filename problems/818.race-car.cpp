// @leetcode id=818 questionId=836 slug=race-car lang=cpp site=leetcode.com title="Race Car"
class Solution {
public:
    int racecar(int target) {
        unordered_map<int, int> memo;
        function<int(int)> dp = [&](int t) -> int {
            if (t == 0) return 0;
            auto it = memo.find(t);
            if (it != memo.end()) return it->second;

            int n = 0;
            while ((1 << n) - 1 < t) n++;

            int best;
            if ((1 << n) - 1 == t) {
                best = n;
            } else {
                best = dp((1 << n) - 1 - t) + n + 1;
                for (int m = 0; m < n - 1; m++) {
                    best = min(best, dp(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
                }
            }

            memo[t] = best;
            return best;
        };

        return dp(target);
    }
};
