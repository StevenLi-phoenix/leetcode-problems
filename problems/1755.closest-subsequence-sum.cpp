// @leetcode id=1755 questionId=1881 slug=closest-subsequence-sum lang=cpp site=leetcode.com title="Closest Subsequence Sum"
class Solution {
public:
    vector<long long> allSums(vector<int>& arr) {
        int n = arr.size();
        vector<long long> sums;
        for (int mask = 0; mask < (1 << n); mask++) {
            long long s = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) s += arr[i];
            }
            sums.push_back(s);
        }
        sort(sums.begin(), sums.end());
        return sums;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        vector<long long> leftSums = allSums(left);
        vector<long long> rightSums = allSums(right);

        long long best = LLONG_MAX;

        for (long long ls : leftSums) {
            long long target = goal - ls;
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
            if (it != rightSums.end()) best = min(best, abs(ls + *it - goal));
            if (it != rightSums.begin()) best = min(best, abs(ls + *prev(it) - goal));
        }

        return (int)best;
    }
};
