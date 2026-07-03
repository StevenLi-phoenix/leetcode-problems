// @leetcode id=3952 questionId=4142 slug=maximum-total-value-of-covered-indices lang=cpp site=leetcode.com title="Maximum Total Value of Covered Indices"
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = s.size();
        long long total = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') { ++i; continue; }
            int p = i;
            while (i < n && s[i] == '1') ++i;
            int q = i - 1;

            if (p == 0) {
                for (int j = p; j <= q; ++j) total += nums[j];
            } else {
                long long sum = 0, mn = LLONG_MAX;
                for (int j = p - 1; j <= q; ++j) {
                    sum += nums[j];
                    mn = min(mn, (long long)nums[j]);
                }
                total += sum - mn;
            }
        }
        return total;
    }
};
