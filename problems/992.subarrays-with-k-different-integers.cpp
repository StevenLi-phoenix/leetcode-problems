// @leetcode id=992 questionId=1034 slug=subarrays-with-k-different-integers lang=cpp site=leetcode.com title="Subarrays with K Different Integers"
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, res = 0;
        unordered_map<int, int> cnt;
        for (int r = 0; r < n; r++) {
            cnt[nums[r]]++;
            while ((int)cnt.size() > k) {
                cnt[nums[l]]--;
                if (cnt[nums[l]] == 0) cnt.erase(nums[l]);
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
