// @leetcode id=2302 questionId=2394 slug=count-subarrays-with-score-less-than-k lang=cpp site=leetcode.com title="Count Subarrays With Score Less Than K"
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long answer = 0;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }
            answer += (right - left + 1);
        }

        return answer;
    }
};
