// @leetcode id=1018 questionId=1071 slug=binary-prefix-divisible-by-5 lang=cpp site=leetcode.com title="Binary Prefix Divisible By 5"
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int cur = 0;
        for (int bit : nums) {
            cur = (cur * 2 + bit) % 5;
            result.push_back(cur == 0);
        }
        return result;
    }
};
