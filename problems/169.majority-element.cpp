// @leetcode id=169 questionId=169 slug=majority-element lang=cpp site=leetcode.com title="Majority Element"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int v : nums) {
            if (count == 0) candidate = v;
            count += (v == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
