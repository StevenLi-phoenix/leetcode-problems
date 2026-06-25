// @leetcode id=2719 questionId=2757 slug=count-of-integers lang=cpp site=leetcode.com title="Count of Integers"
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        const int MOD = 1e9 + 7;

        auto countUpto = [&](string num) -> long long {
            int n = num.size();
            vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(max_sum + 2, vector<long long>(2, -1)));

            function<long long(int, int, int)> solve = [&](int pos, int sum, int tight) -> long long {
                if (sum > max_sum) return 0;
                if (pos == n) {
                    return (sum >= min_sum && sum <= max_sum) ? 1 : 0;
                }

                if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

                int limit = tight ? (num[pos] - '0') : 9;
                long long res = 0;

                for (int digit = 0; digit <= limit; digit++) {
                    int new_tight = tight && (digit == limit);
                    res = (res + solve(pos + 1, sum + digit, new_tight)) % MOD;
                }

                return dp[pos][sum][tight] = res;
            };

            return solve(0, 0, 1);
        };

        auto subtract_one = [](string num) -> string {
            int i = num.size() - 1;
            while (i >= 0 && num[i] == '0') {
                num[i] = '9';
                i--;
            }
            if (i >= 0) {
                num[i]--;
            }

            int start = 0;
            while (start < num.size() && num[start] == '0') {
                start++;
            }

            return (start == num.size()) ? "0" : num.substr(start);
        };

        long long ans = (countUpto(num2) - countUpto(subtract_one(num1)) + MOD) % MOD;
        return ans;
    }
};
