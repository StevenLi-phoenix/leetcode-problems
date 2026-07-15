// @leetcode id=264 questionId=264 slug=ugly-number-ii lang=cpp site=leetcode.com title="Ugly Number II"
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> ugly(n);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            long long next2 = ugly[i2] * 2, next3 = ugly[i3] * 3, next5 = ugly[i5] * 5;
            long long next = min({next2, next3, next5});
            ugly[i] = next;
            if (next == next2) i2++;
            if (next == next3) i3++;
            if (next == next5) i5++;
        }
        return (int)ugly[n - 1];
    }
};
