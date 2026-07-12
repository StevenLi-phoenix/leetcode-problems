// @leetcode id=2104 questionId=2227 slug=sum-of-subarray-ranges lang=cpp site=leetcode.com title="Sum of Subarray Ranges"
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // n <= 1000, so an O(n^2) scan (extend each subarray's running
        // min/max) comfortably fits within limits.
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int mn = nums[i], mx = nums[i];
            for (int j = i; j < n; j++) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                total += mx - mn;
            }
        }
        return total;
    }
};
