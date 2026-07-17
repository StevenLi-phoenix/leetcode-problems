// @leetcode id=3495 questionId=3744 slug=minimum-operations-to-make-array-elements-zero lang=cpp site=leetcode.com title="Minimum Operations to Make Array Elements Zero"
class Solution {
public:
    long long prefixSum(long long N) {
        if (N <= 0) return 0;
        long long total = 0;
        long long low = 1;
        int k = 1;
        while (low <= N) {
            long long high = low * 4 - 1;
            long long actualHigh = min(high, N);
            long long count = actualHigh - low + 1;
            total += count * (long long)k;
            low = high + 1;
            k++;
        }
        return total;
    }

    int weightOf(long long x) {
        int k = 0;
        while (x > 0) {
            x /= 4;
            k++;
        }
        return k;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long answer = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long sumW = prefixSum(r) - prefixSum(l - 1);
            long long maxW = weightOf(r);
            long long ops = max(maxW, (sumW + 1) / 2);
            answer += ops;
        }
        return answer;
    }
};
