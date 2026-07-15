// @leetcode id=3255 questionId=3523 slug=find-the-power-of-k-size-subarrays-ii lang=cpp site=leetcode.com title="Find the Power of K-Size Subarrays II"
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> runLen(n, 1);
        for (int i = 1; i < n; i++) {
            runLen[i] = (nums[i] == nums[i - 1] + 1) ? runLen[i - 1] + 1 : 1;
        }

        vector<int> result(n - k + 1);
        for (int i = 0; i + k - 1 < n; i++) {
            int end = i + k - 1;
            result[i] = (runLen[end] >= k) ? nums[end] : -1;
        }
        return result;
    }
};
