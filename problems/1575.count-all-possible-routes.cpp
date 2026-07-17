// @leetcode id=1575 questionId=1680 slug=count-all-possible-routes lang=cpp site=leetcode.com title="Count All Possible Routes"
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const long long MOD = 1e9 + 7;
        int n = locations.size();
        vector<vector<long long>> memo(n, vector<long long>(fuel + 1, -1));

        function<long long(int, int)> dp = [&](int city, int remaining) -> long long {
            if (memo[city][remaining] != -1) return memo[city][remaining];

            long long ways = (city == finish) ? 1 : 0;
            for (int j = 0; j < n; j++) {
                if (j == city) continue;
                int cost = abs(locations[city] - locations[j]);
                if (cost <= remaining) {
                    ways = (ways + dp(j, remaining - cost)) % MOD;
                }
            }

            memo[city][remaining] = ways;
            return ways;
        };

        return (int)dp(start, fuel);
    }
};
