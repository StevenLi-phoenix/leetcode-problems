// @leetcode id=3727 questionId=4078 slug=maximum-alternating-sum-of-squares lang=cpp site=leetcode.com title="Maximum Alternating Sum of Squares"
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // Use abs values - sort descending by abs value
        vector<long long> absNums;
        for (int x : nums) absNums.push_back((long long)abs(x));
        sort(absNums.rbegin(), absNums.rend());
        
        // Even positions (0, 2, ...) are added, odd positions subtracted
        // We have ceil(n/2) even positions and floor(n/2) odd positions
        // To maximize: put largest abs values at even positions
        int evenCount = (n + 1) / 2;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < evenCount) {
                ans += absNums[i] * absNums[i];
            } else {
                ans -= absNums[i] * absNums[i];
            }
        }
        return ans;
    }
};
