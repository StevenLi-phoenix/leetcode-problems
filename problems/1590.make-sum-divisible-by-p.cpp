// @leetcode id=1590 questionId=1694 slug=make-sum-divisible-by-p lang=cpp site=leetcode.com title="Make Sum Divisible by P"
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int v : nums) total += v;
        long long target = total % p;
        if (target == 0) return 0;

        unordered_map<long long, int> lastIndex;
        lastIndex[0] = -1;
        long long prefix = 0;
        int best = n;
        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;
            long long need = (prefix - target % p + p) % p;
            auto it = lastIndex.find(need);
            if (it != lastIndex.end()) {
                best = min(best, i - it->second);
            }
            lastIndex[prefix] = i;
        }
        return best == n ? -1 : best;
    }
};
