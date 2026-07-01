// @leetcode id=3867 questionId=4242 slug=sum-of-gcd-of-formed-pairs lang=cpp site=leetcode.com title="Sum of GCD of Formed Pairs"
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            sum += gcd(prefixGcd[lo], prefixGcd[hi]);
            lo++; hi--;
        }
        return sum;
    }
};
