// @leetcode id=2149 questionId=2271 slug=rearrange-array-elements-by-sign lang=cpp site=leetcode.com title="Rearrange Array Elements by Sign"
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int pos = 0, neg = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[pos] = nums[i];
                pos += 2;
            } else {
                result[neg] = nums[i];
                neg += 2;
            }
        }
        return result;
    }
};
