// @leetcode id=2172 questionId=2291 slug=maximum-and-sum-of-array lang=cpp site=leetcode.com title="Maximum AND Sum of Array"
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        // Encode each slot's fill count (0,1,2) as a base-3 digit of a
        // state mask; the number of nums already placed equals the digit
        // sum, so memoizing purely on mask (dropping the explicit index)
        // is valid.
        vector<int> pow3(numSlots + 1);
        pow3[0] = 1;
        for (int i = 1; i <= numSlots; i++) pow3[i] = pow3[i - 1] * 3;

        int n = nums.size();
        int totalStates = pow3[numSlots];
        vector<int> memo(totalStates, -1);

        function<int(int, int)> solve = [&](int idx, int mask) -> int {
            if (idx == n) return 0;
            if (memo[mask] != -1) return memo[mask];

            int best = 0;
            for (int slot = 0; slot < numSlots; slot++) {
                int digit = (mask / pow3[slot]) % 3;
                if (digit < 2) {
                    int newMask = mask + pow3[slot];
                    int val = (nums[idx] & (slot + 1)) + solve(idx + 1, newMask);
                    best = max(best, val);
                }
            }
            memo[mask] = best;
            return best;
        };

        return solve(0, 0);
    }
};
