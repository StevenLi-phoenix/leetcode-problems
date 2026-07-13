// @leetcode id=3113 questionId=3382 slug=find-the-number-of-subarrays-where-boundary-elements-are-maximum lang=cpp site=leetcode.com title="Find the Number of Subarrays Where Boundary Elements Are Maximum"
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        // Monotonic stack of (value, count) where count = number of prior
        // positions with this value that are still valid subarray starts
        // (no larger element has appeared since). Each new occurrence
        // pairs with every prior one at the same max, plus itself alone.
        vector<pair<int, long long>> stack;
        long long ans = 0;

        for (int x : nums) {
            while (!stack.empty() && stack.back().first < x) stack.pop_back();

            long long prevCount = (!stack.empty() && stack.back().first == x) ? stack.back().second : 0;
            long long newCount = prevCount + 1;
            ans += newCount;

            if (!stack.empty() && stack.back().first == x) {
                stack.back().second = newCount;
            } else {
                stack.push_back({x, newCount});
            }
        }
        return ans;
    }
};
