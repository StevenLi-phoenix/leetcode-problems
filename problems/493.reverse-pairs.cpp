// @leetcode id=493 questionId=493 slug=reverse-pairs lang=cpp site=leetcode.com title="Reverse Pairs"
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeCount(nums, 0, (int)nums.size() - 1);
    }

private:
    int mergeCount(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int count = mergeCount(nums, lo, mid) + mergeCount(nums, mid + 1, hi);

        int j = mid + 1;
        for (int i = lo; i <= mid; ++i) {
            while (j <= hi && (long long)nums[i] > 2LL * nums[j]) ++j;
            count += j - (mid + 1);
        }

        vector<int> merged;
        merged.reserve(hi - lo + 1);
        int p1 = lo, p2 = mid + 1;
        while (p1 <= mid && p2 <= hi) {
            if (nums[p1] <= nums[p2]) merged.push_back(nums[p1++]);
            else merged.push_back(nums[p2++]);
        }
        while (p1 <= mid) merged.push_back(nums[p1++]);
        while (p2 <= hi) merged.push_back(nums[p2++]);
        for (int k = lo; k <= hi; ++k) nums[k] = merged[k - lo];

        return count;
    }
};
