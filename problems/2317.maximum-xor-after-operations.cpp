// @leetcode id=2317 questionId=2402 slug=maximum-xor-after-operations lang=cpp site=leetcode.com title="Maximum XOR After Operations "
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        // nums[i] AND (nums[i] XOR x) can clear any subset of nums[i]'s set
        // bits (never set new ones), so each bit that's on in ANY element
        // can independently be kept there and cleared everywhere else,
        // making the OR of all elements the achievable maximum XOR.
        int result = 0;
        for (int v : nums) result |= v;
        return result;
    }
};
