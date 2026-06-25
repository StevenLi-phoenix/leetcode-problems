// @leetcode id=3634 questionId=3958 slug=minimum-removals-to-balance-array lang=cpp site=leetcode.com title="Minimum Removals to Balance Array"
class Solution {
    public:
    int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = n - 1;
    for (int l = 0; l < n; l++) {
    long long maxVal = (long long)nums[l] * k;
    int r = (int)(upper_bound(nums.begin(), nums.end(), maxVal) - nums.begin()) - 1;
    if (r >= l) {
    ans = min(ans, l + (n - 1 - r));
    }
    }
    return ans;
    }
    };
