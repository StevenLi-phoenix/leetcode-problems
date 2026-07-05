// @leetcode id=2932 questionId=3193 slug=maximum-strong-pair-xor-i lang=cpp site=leetcode.com title="Maximum Strong Pair XOR I"
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = nums[i], y = nums[j];
                if (abs(x - y) <= min(x, y)) {
                    best = max(best, x ^ y);
                }
            }
        }
        return best;
    }
};
