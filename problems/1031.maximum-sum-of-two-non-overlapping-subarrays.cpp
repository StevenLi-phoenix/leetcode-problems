// @leetcode id=1031 questionId=1096 slug=maximum-sum-of-two-non-overlapping-subarrays lang=cpp site=leetcode.com title="Maximum Sum of Two Non-Overlapping Subarrays"
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        auto solve = [&](int lenA, int lenB) {
            int best = 0;
            int bestA = 0;
            for (int i = lenA + lenB; i <= n; i++) {
                int aEnd = i - lenB;
                int aSum = prefix[aEnd] - prefix[aEnd - lenA];
                bestA = max(bestA, aSum);
                int bSum = prefix[i] - prefix[i - lenB];
                best = max(best, bestA + bSum);
            }
            return best;
        };

        return max(solve(firstLen, secondLen), solve(secondLen, firstLen));
    }
};
