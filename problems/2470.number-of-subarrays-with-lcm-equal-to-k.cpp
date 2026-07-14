// @leetcode id=2470 questionId=2557 slug=number-of-subarrays-with-lcm-equal-to-k lang=cpp site=leetcode.com title="Number of Subarrays With LCM Equal to K"
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long curLcm = 1;
            for (int j = i; j < n; j++) {
                long long g = gcd(curLcm, (long long)nums[j]);
                curLcm = curLcm / g * nums[j];
                if (curLcm > k) break;
                if (curLcm == k) count++;
            }
        }
        return count;
    }
};
