// @leetcode id=689 questionId=689 slug=maximum-sum-of-3-non-overlapping-subarrays lang=cpp site=leetcode.com title="Maximum Sum of 3 Non-Overlapping Subarrays"
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int numWindows = n - k + 1;
        vector<long long> windowSum(numWindows);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) windowSum[i - k + 1] = sum;
        }

        vector<int> left(numWindows);
        left[0] = 0;
        for (int i = 1; i < numWindows; ++i) {
            left[i] = (windowSum[i] > windowSum[left[i - 1]]) ? i : left[i - 1];
        }

        vector<int> right(numWindows);
        right[numWindows - 1] = numWindows - 1;
        for (int i = numWindows - 2; i >= 0; --i) {
            right[i] = (windowSum[i] >= windowSum[right[i + 1]]) ? i : right[i + 1];
        }

        long long best = -1;
        vector<int> ans(3);
        for (int j = k; j <= numWindows - 1 - k; ++j) {
            int l = left[j - k];
            int r = right[j + k];
            long long total = windowSum[l] + windowSum[j] + windowSum[r];
            if (total > best) {
                best = total;
                ans = {l, j, r};
            }
        }
        return ans;
    }
};
