// @leetcode id=553 questionId=553 slug=optimal-division lang=cpp site=leetcode.com title="Optimal Division"
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        // Maximizing nums[0]/x1/x2/.../xn-1 means minimizing the divisor
        // chain, and dividing by a fraction (rather than by each xi
        // separately) is always smaller, so grouping everything after the
        // first element into one parenthesized chain is optimal.
        int n = nums.size();
        if (n == 1) return to_string(nums[0]);
        if (n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);

        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < n; i++) res += "/" + to_string(nums[i]);
        res += ")";
        return res;
    }
};
