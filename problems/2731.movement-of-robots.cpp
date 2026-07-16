// @leetcode id=2731 questionId=2787 slug=movement-of-robots lang=cpp site=leetcode.com title="Movement of Robots"
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            pos[i] = (long long)nums[i] + (s[i] == 'R' ? (long long)d : -(long long)d);
        }
        sort(pos.begin(), pos.end());

        long long answer = 0;
        long long prefix = 0;
        for (int i = 0; i < n; i++) {
            long long posMod = ((pos[i] % MOD) + MOD) % MOD;
            long long term = (posMod * i % MOD - prefix % MOD + MOD) % MOD;
            answer = (answer + term) % MOD;
            prefix = (prefix + posMod) % MOD;
        }
        return (int)answer;
    }
};
