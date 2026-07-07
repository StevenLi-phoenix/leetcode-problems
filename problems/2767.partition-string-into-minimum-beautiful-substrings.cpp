// @leetcode id=2767 questionId=2883 slug=partition-string-into-minimum-beautiful-substrings lang=cpp site=leetcode.com title="Partition String Into Minimum Beautiful Substrings"
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();

        unordered_set<long long> powersOf5;
        for (long long p = 1; p < (1LL << n); p *= 5) powersOf5.insert(p);

        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[j] == '0' || dp[j] == INF) continue;
                long long value = stoll(s.substr(j, i - j), nullptr, 2);
                if (powersOf5.count(value)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};
