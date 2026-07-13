// @leetcode id=3969 questionId=4318 slug=valid-subarrays-with-matching-sum-digits-i lang=cpp site=leetcode.com title="Valid Subarrays With Matching Sum Digits I"
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;
        for (int l = 0; l < n; l++) {
            long long sum = 0;
            for (int r = l; r < n; r++) {
                sum += nums[r];
                if (sum % 10 != x) continue;
                long long firstDigit = sum;
                while (firstDigit >= 10) firstDigit /= 10;
                if (firstDigit == x) count++;
            }
        }
        return count;
    }
};
