// @leetcode id=982 questionId=1024 slug=triples-with-bitwise-and-equal-to-zero lang=cpp site=leetcode.com title="Triples with Bitwise AND Equal To Zero"
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int BITS = 16;
        const int SIZE = 1 << BITS;
        vector<long long> cnt(SIZE, 0);
        for (int a : nums) for (int b : nums) cnt[a & b]++;

        // Sum-over-subsets DP: f[mask] = sum of cnt[x] for all x that are a
        // submask of mask.
        vector<long long> f = cnt;
        for (int bit = 0; bit < BITS; bit++) {
            for (int mask = 0; mask < SIZE; mask++) {
                if (mask & (1 << bit)) f[mask] += f[mask ^ (1 << bit)];
            }
        }

        long long total = 0;
        for (int c : nums) {
            int complement = (~c) & (SIZE - 1);
            total += f[complement];
        }
        return (int)total;
    }
};
