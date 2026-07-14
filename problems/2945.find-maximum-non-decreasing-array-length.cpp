// @leetcode id=2945 questionId=3211 slug=find-maximum-non-decreasing-array-length lang=cpp site=leetcode.com title="Find Maximum Non-decreasing Array Length"
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<int> dp(n + 1, 0);
        vector<long long> last(n + 1, 0);
        const long long NEG_INF = LLONG_MIN / 2;
        last[0] = NEG_INF;

        auto threshold = [&](int j) -> long long { return prefix[j] + last[j]; };

        vector<int> dq = {0}; // indices with strictly increasing threshold

        for (int i = 1; i <= n; i++) {
            // Binary search for the rightmost j in dq with threshold(j) <= prefix[i].
            int lo = 0, hi = (int)dq.size() - 1, pos = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (threshold(dq[mid]) <= prefix[i]) { pos = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            int j = dq[pos];
            dp[i] = dp[j] + 1;
            last[i] = prefix[i] - prefix[j];

            while (!dq.empty() && threshold(i) <= threshold(dq.back())) dq.pop_back();
            dq.push_back(i);
        }
        return dp[n];
    }
};
