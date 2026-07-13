// @leetcode id=3209 questionId=3466 slug=number-of-subarrays-with-and-value-of-k lang=cpp site=leetcode.com title="Number of Subarrays With AND Value of K"
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // For each end index, track (AND value, count of subarrays ending
        // here with that value) for subarrays ending at the previous index,
        // AND each with nums[i], append nums[i] itself, then merge adjacent
        // equal values. AND values only lose bits as the window grows, so
        // this list has O(log(max value)) distinct entries at any time.
        vector<pair<int, long long>> prev;
        long long ans = 0;
        for (int x : nums) {
            vector<pair<int, long long>> cur;
            cur.push_back({x, 1});
            for (auto& [val, cnt] : prev) {
                int newVal = val & x;
                if (!cur.empty() && cur.back().first == newVal) cur.back().second += cnt;
                else cur.push_back({newVal, cnt});
            }
            for (auto& [val, cnt] : cur)
                if (val == k) ans += cnt;
            prev = move(cur);
        }
        return ans;
    }
};
