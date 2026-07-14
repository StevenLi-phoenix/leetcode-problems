// @leetcode id=3171 questionId=3436 slug=find-subarray-with-bitwise-or-closest-to-k lang=cpp site=leetcode.com title="Find Subarray With Bitwise OR Closest to K"
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        long long best = LLONG_MAX;
        vector<int> prev; // OR values of all subarrays ending at the previous index
        for (int v : nums) {
            vector<int> cur;
            cur.push_back(v);
            for (int p : prev) cur.push_back(p | v);
            sort(cur.begin(), cur.end());
            cur.erase(unique(cur.begin(), cur.end()), cur.end());
            for (int c : cur) best = min(best, (long long)abs((long long)c - k));
            prev = cur;
        }
        return (int)best;
    }
};
