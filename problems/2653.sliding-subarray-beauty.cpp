// @leetcode id=2653 questionId=2751 slug=sliding-subarray-beauty lang=cpp site=leetcode.com title="Sliding Subarray Beauty"
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int cnt[51] = {0};
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) cnt[-nums[i]]++;
            if (i >= k) {
                if (nums[i - k] < 0) cnt[-nums[i - k]]--;
            }
            if (i >= k - 1) {
                int remaining = x;
                int beauty = 0;
                for (int v = 50; v >= 1; v--) {
                    remaining -= cnt[v];
                    if (remaining <= 0) {
                        beauty = -v;
                        break;
                    }
                }
                ans.push_back(beauty);
            }
        }
        return ans;
    }
};
