// @leetcode id=2447 questionId=2546 slug=number-of-subarrays-with-gcd-equal-to-k lang=cpp site=leetcode.com title="Number of Subarrays With GCD Equal to K"
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = __gcd(g, nums[j]);
                if (g == k) count++;
                if (g < k) break; // GCD can only decrease
            }
        }
        
        return count;
    }
};
