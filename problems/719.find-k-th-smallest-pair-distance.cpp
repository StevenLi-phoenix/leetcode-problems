// @leetcode id=719 questionId=719 slug=find-k-th-smallest-pair-distance lang=cpp site=leetcode.com title="Find K-th Smallest Pair Distance"
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = nums[n - 1] - nums[0];

        auto countLE = [&](int mid) {
            long long count = 0;
            int left = 0;
            for (int right = 0; right < n; right++) {
                while (nums[right] - nums[left] > mid) left++;
                count += right - left;
            }
            return count;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};
