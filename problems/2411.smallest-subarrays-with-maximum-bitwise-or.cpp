// @leetcode id=2411 questionId=2498 slug=smallest-subarrays-with-maximum-bitwise-or lang=cpp site=leetcode.com title="Smallest Subarrays With Maximum Bitwise OR"
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> lastSeen(30, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 30; b++) {
                if (nums[i] & (1 << b)) lastSeen[b] = i;
            }
            int farthest = i;
            for (int b = 0; b < 30; b++) {
                farthest = max(farthest, lastSeen[b]);
            }
            answer[i] = farthest - i + 1;
        }
        return answer;
    }
};
