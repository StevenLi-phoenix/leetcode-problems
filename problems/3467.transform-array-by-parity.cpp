// @leetcode id=3467 questionId=3778 slug=transform-array-by-parity lang=cpp site=leetcode.com title="Transform Array by Parity"
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int evenCount = 0;
        for (int x : nums) {
            if (x % 2 == 0) evenCount++;
        }
        vector<int> result(nums.size(), 1);
        for (int i = 0; i < evenCount; i++) {
            result[i] = 0;
        }
        return result;
    }
};
