// @leetcode id=2772 questionId=2878 slug=apply-operations-to-make-all-array-elements-equal-to-zero lang=cpp site=leetcode.com title="Apply Operations to Make All Array Elements Equal to Zero"
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);
        long long decreaseSoFar = 0;
        for (int i = 0; i < n; i++) {
            decreaseSoFar += diff[i];
            long long required = nums[i] - decreaseSoFar;
            if (required < 0) return false;
            if (required > 0) {
                if (i + k > n) return false;
                decreaseSoFar += required;
                diff[i + k] -= required;
            }
        }
        return true;
    }
};
