// @leetcode id=2972 questionId=3248 slug=count-the-number-of-incremovable-subarrays-ii lang=cpp site=leetcode.com title="Count the Number of Incremovable Subarrays II"
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        int p = 1;
        while (p < n && nums[p] > nums[p - 1]) p++;
        // nums[0..p-1] is the maximal strictly increasing prefix, p = its length

        if (p == n) {
            return (long long)n * (n + 1) / 2;
        }

        int q = n - 2;
        while (q >= 0 && nums[q] < nums[q + 1]) q--;
        q++;
        // nums[q..n-1] is the maximal strictly increasing suffix

        long long total = 0;
        int s = q;

        for (int l = 0; l <= p; l++) {
            int candidate = max(s, l + 1);
            while (candidate < n && l > 0 && nums[candidate] <= nums[l - 1]) candidate++;
            s = candidate;
            total += (n - s + 1);
        }

        return total;
    }
};
