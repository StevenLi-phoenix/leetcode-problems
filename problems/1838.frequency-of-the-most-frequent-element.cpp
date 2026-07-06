// @leetcode id=1838 questionId=1966 slug=frequency-of-the-most-frequent-element lang=cpp site=leetcode.com title="Frequency of the Most Frequent Element"
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        int left = 0;
        int best = 1;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
