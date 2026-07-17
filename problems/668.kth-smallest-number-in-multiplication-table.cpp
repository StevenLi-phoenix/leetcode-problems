// @leetcode id=668 questionId=668 slug=kth-smallest-number-in-multiplication-table lang=cpp site=leetcode.com title="Kth Smallest Number in Multiplication Table"
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long count = 0;
            for (int i = 1; i <= m; i++) {
                count += min(n, mid / i);
            }
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};
