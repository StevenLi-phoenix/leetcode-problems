// @leetcode id=2537 questionId=2626 slug=count-the-number-of-good-subarrays lang=cpp site=leetcode.com title="Count the Number of Good Subarrays"
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        long long pairs = 0, total = 0;
        int left = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            pairs += count[nums[right]];
            count[nums[right]]++;

            while (pairs >= k) {
                count[nums[left]]--;
                pairs -= count[nums[left]];
                left++;
            }
            total += left;
        }
        return total;
    }
};
