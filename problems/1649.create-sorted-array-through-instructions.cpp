// @leetcode id=1649 questionId=1772 slug=create-sorted-array-through-instructions lang=cpp site=leetcode.com title="Create Sorted Array through Instructions"
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const long long MOD = 1'000'000'007;
        int maxVal = 100000;
        vector<int> bit(maxVal + 2, 0);
        auto update = [&](int i) {
            for (; i <= maxVal; i += i & (-i)) bit[i]++;
        };
        auto prefixSum = [&](int i) {
            int res = 0;
            for (; i > 0; i -= i & (-i)) res += bit[i];
            return res;
        };

        long long total = 0;
        int inserted = 0;
        for (int x : instructions) {
            int lessCount = prefixSum(x - 1);
            int lessOrEqual = prefixSum(x);
            int greaterCount = inserted - lessOrEqual;
            total = (total + min(lessCount, greaterCount)) % MOD;
            update(x);
            inserted++;
        }
        return (int)total;
    }
};
