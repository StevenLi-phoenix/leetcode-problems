// @leetcode id=2588 questionId=2656 slug=count-the-number-of-beautiful-subarrays lang=cpp site=leetcode.com title="Count the Number of Beautiful Subarrays"
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,long long> cnt;
        cnt[0] = 1;
        int xorSum = 0;
        long long ans = 0;
        for (int x : nums) {
            xorSum ^= x;
            ans += cnt[xorSum];
            cnt[xorSum]++;
        }
        return ans;
    }
};
