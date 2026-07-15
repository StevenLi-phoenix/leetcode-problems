// @leetcode id=2576 questionId=2712 slug=find-the-maximum-number-of-marked-indices lang=cpp site=leetcode.com title="Find the Maximum Number of Marked Indices"
class Solution {
public:
    bool canPair(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            if (2 * nums[i] > nums[n - k + i]) return false;
        }
        return true;
    }

    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = n / 2;
        int best = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPair(nums, mid)) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best * 2;
    }
};
