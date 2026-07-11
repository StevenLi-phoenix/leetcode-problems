// @leetcode id=2560 questionId=2690 slug=house-robber-iv lang=cpp site=leetcode.com title="House Robber IV"
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // Binary search the answer: can we pick >= k non-adjacent houses all <= cap?
        auto feasible = [&](int cap) {
            int count = 0;
            for (int i = 0; i < (int)nums.size(); i++) {
                if (nums[i] <= cap) {
                    count++;
                    i++; // skip adjacent house
                }
            }
            return count >= k;
        };

        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
