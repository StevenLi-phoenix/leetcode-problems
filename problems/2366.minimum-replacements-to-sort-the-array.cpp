// @leetcode id=2366 questionId=2450 slug=minimum-replacements-to-sort-the-array lang=cpp site=leetcode.com title="Minimum Replacements to Sort the Array"
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ops = 0;
        long long limit = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= limit) {
                limit = nums[i];
                continue;
            }
            long long k = (nums[i] + limit - 1) / limit;
            ops += k - 1;
            limit = nums[i] / k;
        }

        return ops;
    }
};
