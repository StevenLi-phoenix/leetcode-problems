// @leetcode id=2968 questionId=3196 slug=apply-operations-to-maximize-frequency-score lang=cpp site=leetcode.com title="Apply Operations to Maximize Frequency Score"
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];

        auto costToEqualizeMedian = [&](int left, int right) -> long long {
            int mid = (left + right) / 2;
            long long m = nums[mid];
            long long leftCost = m * (mid - left + 1) - (prefix[mid + 1] - prefix[left]);
            long long rightCost = (prefix[right + 1] - prefix[mid + 1]) - m * (right - mid);
            return leftCost + rightCost;
        };

        int best = 1;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (costToEqualizeMedian(left, right) > k) ++left;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
