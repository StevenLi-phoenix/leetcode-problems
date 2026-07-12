// @leetcode id=327 questionId=327 slug=count-of-range-sum lang=cpp site=leetcode.com title="Count of Range Sum"
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> buf(n + 1);
        return mergeCount(prefix, buf, 0, n + 1, lower, upper);
    }

private:
    // Counts pairs (i,j), i<j, with prefix[j]-prefix[i] in [lower,upper]
    // among prefix[lo..hi], then sorts prefix[lo..hi] in place (merge sort).
    int mergeCount(vector<long long>& prefix, vector<long long>& buf, int lo, int hi, int lower, int upper) {
        if (hi - lo <= 1) return 0;
        int mid = lo + (hi - lo) / 2;
        int count = mergeCount(prefix, buf, lo, mid, lower, upper) + mergeCount(prefix, buf, mid, hi, lower, upper);

        // For each j in the right half, count i in the left half with
        // prefix[j]-upper <= prefix[i] <= prefix[j]-lower.
        int lo2 = lo, hi2 = lo;
        for (int j = mid; j < hi; j++) {
            while (lo2 < mid && prefix[lo2] < prefix[j] - upper) lo2++;
            while (hi2 < mid && prefix[hi2] <= prefix[j] - lower) hi2++;
            count += hi2 - lo2;
        }

        int i = lo, j = mid, k = lo;
        while (i < mid && j < hi) buf[k++] = (prefix[i] <= prefix[j]) ? prefix[i++] : prefix[j++];
        while (i < mid) buf[k++] = prefix[i++];
        while (j < hi) buf[k++] = prefix[j++];
        for (int p = lo; p < hi; p++) prefix[p] = buf[p];
        return count;
    }
};
