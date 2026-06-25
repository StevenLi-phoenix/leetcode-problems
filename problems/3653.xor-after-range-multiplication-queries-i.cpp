// @leetcode id=3653 questionId=3974 slug=xor-after-range-multiplication-queries-i lang=cpp site=leetcode.com title="XOR After Range Multiplication Queries I"
class Solution {
    public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    const long long MOD = 1e9 + 7;
    for (auto& q : queries) {
    int l = q[0], r = q[1], k = q[2];
    long long v = q[3];
    for (int idx = l; idx <= r; idx += k) {
    nums[idx] = (1LL * nums[idx] * v) % MOD;
    }
    }
    int result = 0;
    for (int x : nums) {
    result ^= x;
    }
    return result;
    }
    };
