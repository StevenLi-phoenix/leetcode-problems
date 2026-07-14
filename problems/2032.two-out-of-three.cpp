// @leetcode id=2032 questionId=2159 slug=two-out-of-three lang=cpp site=leetcode.com title="Two Out of Three"
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> mask(101, 0);
        for (int v : nums1) mask[v] |= 1;
        for (int v : nums2) mask[v] |= 2;
        for (int v : nums3) mask[v] |= 4;

        vector<int> result;
        for (int v = 1; v <= 100; v++) {
            int bits = mask[v];
            if (bits && (bits & (bits - 1))) result.push_back(v);
        }
        return result;
    }
};
