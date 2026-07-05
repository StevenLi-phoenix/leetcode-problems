// @leetcode id=3819 questionId=4171 slug=rotate-non-negative-elements lang=cpp site=leetcode.com title="Rotate Non Negative Elements"
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> indices;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] >= 0) indices.push_back(i);
        }
        int m = indices.size();
        if (m == 0) return nums;

        vector<int> vals(m);
        for (int i = 0; i < m; ++i) vals[i] = nums[indices[i]];

        int shift = k % m;
        vector<int> result(nums);
        for (int i = 0; i < m; ++i) {
            result[indices[i]] = vals[(i + shift) % m];
        }
        return result;
    }
};
