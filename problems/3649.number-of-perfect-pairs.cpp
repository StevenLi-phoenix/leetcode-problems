// @leetcode id=3649 questionId=3963 slug=number-of-perfect-pairs lang=cpp site=leetcode.com title="Number of Perfect Pairs"
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // For any reals a,b: min(|a-b|,|a+b|) = ||a|-|b|| and
        // max(|a-b|,|a+b|) = |a|+|b|, regardless of sign. The max
        // condition (|a|+|b| >= max(|a|,|b|)) is always true, so the pair
        // is perfect iff ||a|-|b|| <= min(|a|,|b|), i.e. the larger
        // absolute value is at most twice the smaller one.
        int n = nums.size();
        vector<long long> absVals(n);
        for (int i = 0; i < n; i++) absVals[i] = abs((long long)nums[i]);
        sort(absVals.begin(), absVals.end());

        long long count = 0;
        for (int j = 0; j < n; j++) {
            long long need = (absVals[j] + 1) / 2; // smallest x with 2x >= absVals[j]
            int lo = lower_bound(absVals.begin(), absVals.begin() + j, need) - absVals.begin();
            count += j - lo;
        }
        return count;
    }
};
