// @leetcode id=3737 questionId=4074 slug=count-subarrays-with-majority-element-i lang=cpp site=leetcode.com title="Count Subarrays With Majority Element I"
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) cnt++;
                // subarray length = j - i + 1
                // majority: cnt * 2 > (j - i + 1)
                if (cnt * 2 > j - i + 1) ans++;
            }
        }
        return ans;
    }
};
