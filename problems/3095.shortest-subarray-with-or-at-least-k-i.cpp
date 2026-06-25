// @leetcode id=3095 questionId=3381 slug=shortest-subarray-with-or-at-least-k-i lang=cpp site=leetcode.com title="Shortest Subarray With OR at Least K I"
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int orVal = 0;
            for (int j = i; j < n; j++) {
                orVal |= nums[j];
                if (orVal >= k) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
