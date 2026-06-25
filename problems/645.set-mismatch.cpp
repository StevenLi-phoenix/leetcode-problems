// @leetcode id=645 questionId=645 slug=set-mismatch lang=cpp site=leetcode.com title="Set Mismatch"
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        for (int x : nums) cnt[x]++;
        int dup = -1, miss = -1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 2) dup = i;
            if (cnt[i] == 0) miss = i;
        }
        return {dup, miss};
    }
};
