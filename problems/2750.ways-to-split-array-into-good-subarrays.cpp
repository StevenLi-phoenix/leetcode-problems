// @leetcode id=2750 questionId=2867 slug=ways-to-split-array-into-good-subarrays lang=cpp site=leetcode.com title="Ways to Split Array Into Good Subarrays"
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        vector<int> ones;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 1) ones.push_back(i);
        }
        if (ones.empty()) return 0;

        long long result = 1;
        for (int i = 1; i < (int)ones.size(); i++) {
            long long gap = ones[i] - ones[i - 1];
            result = (result * gap) % MOD;
        }
        return (int)result;
    }
};
