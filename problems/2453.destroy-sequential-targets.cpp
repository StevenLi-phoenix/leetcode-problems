// @leetcode id=2453 questionId=2548 slug=destroy-sequential-targets lang=cpp site=leetcode.com title="Destroy Sequential Targets"
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> count;
        int best = 0;
        for (int x : nums) best = max(best, ++count[x % space]);

        int ans = INT_MAX;
        for (int x : nums)
            if (count[x % space] == best) ans = min(ans, x);
        return ans;
    }
};
