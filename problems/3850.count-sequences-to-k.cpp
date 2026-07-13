// @leetcode id=3850 questionId=4065 slug=count-sequences-to-k lang=cpp site=leetcode.com title="Count Sequences to K"
class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        // Every value stays a product of powers of 2, 3, 5 (since
        // nums[i] <= 6), so track val as an exponent triple (a,b,c) and
        // count paths through that state space instead of exact rationals.
        auto factorize = [](long long v, int& e2, int& e3, int& e5) -> bool {
            e2 = e3 = e5 = 0;
            while (v % 2 == 0) { v /= 2; e2++; }
            while (v % 3 == 0) { v /= 3; e3++; }
            while (v % 5 == 0) { v /= 5; e5++; }
            return v == 1;
        };

        int ka, kb, kc;
        if (!factorize(k, ka, kb, kc)) return 0;

        vector<array<int, 3>> deltas(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            int e2, e3, e5;
            factorize(nums[i], e2, e3, e5); // nums[i] <= 6, always factorizes over {2,3,5}
            deltas[i] = {e2, e3, e5};
        }

        map<array<int, 3>, long long> dp;
        dp[{0, 0, 0}] = 1;

        for (auto& d : deltas) {
            map<array<int, 3>, long long> next;
            for (auto& [state, cnt] : dp) {
                array<int, 3> same = state;
                array<int, 3> mul = {state[0] + d[0], state[1] + d[1], state[2] + d[2]};
                array<int, 3> div = {state[0] - d[0], state[1] - d[1], state[2] - d[2]};
                next[same] += cnt;
                next[mul] += cnt;
                next[div] += cnt;
            }
            dp = move(next);
        }

        auto it = dp.find({ka, kb, kc});
        return it == dp.end() ? 0 : (int)it->second;
    }
};
