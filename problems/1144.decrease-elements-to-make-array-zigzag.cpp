// @leetcode id=1144 questionId=1247 slug=decrease-elements-to-make-array-zigzag lang=cpp site=leetcode.com title="Decrease Elements To Make Array Zigzag"
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int cost[2] = {0, 0};
        for (int parity = 0; parity < 2; parity++) {
            for (int i = parity; i < n; i += 2) {
                int neighborMin = INT_MAX;
                if (i > 0) neighborMin = min(neighborMin, nums[i - 1]);
                if (i < n - 1) neighborMin = min(neighborMin, nums[i + 1]);
                if (nums[i] >= neighborMin) cost[parity] += nums[i] - neighborMin + 1;
            }
        }
        return min(cost[0], cost[1]);
    }
};
