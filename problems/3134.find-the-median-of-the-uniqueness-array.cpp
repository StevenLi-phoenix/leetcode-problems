// @leetcode id=3134 questionId=3362 slug=find-the-median-of-the-uniqueness-array lang=cpp site=leetcode.com title="Find the Median of the Uniqueness Array"
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long)n * (n + 1) / 2;
        long long targetIdx = (total - 1) / 2; // 0-indexed position in the sorted uniqueness array

        // Count subarrays with distinct-element count <= x via sliding window.
        auto countLE = [&](int x) -> long long {
            unordered_map<int, int> freq;
            long long count = 0;
            int left = 0, distinct = 0;
            for (int right = 0; right < n; right++) {
                if (freq[nums[right]]++ == 0) distinct++;
                while (distinct > x) {
                    if (--freq[nums[left]] == 0) distinct--;
                    left++;
                }
                count += right - left + 1;
            }
            return count;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLE(mid) > targetIdx) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
