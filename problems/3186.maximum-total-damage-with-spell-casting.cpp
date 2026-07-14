// @leetcode id=3186 questionId=3437 slug=maximum-total-damage-with-spell-casting lang=cpp site=leetcode.com title="Maximum Total Damage With Spell Casting"
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> countByValue;
        for (int p : power) countByValue[p]++;

        vector<int> values;
        vector<long long> total;
        for (auto& [v, c] : countByValue) {
            values.push_back(v);
            total.push_back((long long)v * c);
        }

        int n = values.size();
        vector<long long> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            // Find the rightmost index j with values[j] <= values[i] - 3
            // (i.e. skip anything within distance 2 of values[i]).
            int lo = 0, hi = i - 1, j = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (values[mid] <= values[i] - 3) { j = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            long long prev = (j == -1) ? 0 : dp[j + 1];
            dp[i + 1] = max(dp[i], prev + total[i]);
        }
        return dp[n];
    }
};
