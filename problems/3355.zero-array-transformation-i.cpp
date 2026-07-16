// @leetcode id=3355 questionId=3639 slug=zero-array-transformation-i lang=cpp site=leetcode.com title="Zero Array Transformation I"
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto& q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }

        int cover = 0;
        for (int i = 0; i < n; i++) {
            cover += diff[i];
            if (cover < nums[i]) return false;
        }
        return true;
    }
};
