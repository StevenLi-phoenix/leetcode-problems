// @leetcode id=3937 questionId=4300 slug=minimum-operations-to-make-array-modulo-alternating-i lang=cpp site=leetcode.com title="Minimum Operations to Make Array Modulo Alternating I"
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> costEven(k, 0), costOdd(k, 0);

        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;
            for (int r = 0; r < k; r++) {
                int diff = abs(rem - r);
                int circDist = min(diff, k - diff);
                if (i % 2 == 0) costEven[r] += circDist;
                else costOdd[r] += circDist;
            }
        }

        long long best = LLONG_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;
                best = min(best, costEven[x] + costOdd[y]);
            }
        }
        return (int)best;
    }
};
