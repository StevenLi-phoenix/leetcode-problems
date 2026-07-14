// @leetcode id=1829 questionId=1940 slug=maximum-xor-for-each-query lang=cpp site=leetcode.com title="Maximum XOR for Each Query"
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxVal = (1 << maximumBit) - 1;
        int cumXor = 0;
        for (int v : nums) cumXor ^= v;

        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = cumXor ^ maxVal;
            cumXor ^= nums[n - 1 - i];
        }
        return answer;
    }
};
