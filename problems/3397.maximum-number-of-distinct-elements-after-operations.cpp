// @leetcode id=3397 questionId=3620 slug=maximum-number-of-distinct-elements-after-operations lang=cpp site=leetcode.com title="Maximum Number of Distinct Elements After Operations"
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long prev = LLONG_MIN;
        int count = 0;

        for (int num : nums) {
            long long lo = (long long)num - k, hi = (long long)num + k;
            long long candidate = max(lo, prev + 1);
            if (candidate <= hi) {
                ++count;
                prev = candidate;
            }
        }
        return count;
    }
};
