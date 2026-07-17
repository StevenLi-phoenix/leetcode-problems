// @leetcode id=3097 questionId=3380 slug=shortest-subarray-with-or-at-least-k-ii lang=cpp site=leetcode.com title="Shortest Subarray With OR at Least K II"
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCount(30, 0);
        int left = 0;
        int orValue = 0;
        int best = INT_MAX;

        for (int right = 0; right < n; right++) {
            for (int b = 0; b < 30; b++) {
                if (nums[right] & (1 << b)) {
                    bitCount[b]++;
                    orValue |= (1 << b);
                }
            }

            while (left <= right && orValue >= k) {
                best = min(best, right - left + 1);
                for (int b = 0; b < 30; b++) {
                    if (nums[left] & (1 << b)) {
                        bitCount[b]--;
                        if (bitCount[b] == 0) orValue &= ~(1 << b);
                    }
                }
                left++;
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
