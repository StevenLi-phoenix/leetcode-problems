// @leetcode id=1012 questionId=1057 slug=numbers-with-repeated-digits lang=cpp site=leetcode.com title="Numbers With Repeated Digits"
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int L = s.size();

        vector<long long> perm(11);
        perm[0] = 1;
        for (int i = 1; i <= 10; i++) perm[i] = perm[i - 1] * i;

        long long countDistinct = 0;

        // numbers with fewer digits than n
        for (int len = 1; len < L; len++) {
            long long ways = 9; // first digit 1-9
            for (int k = 1; k < len; k++) ways *= (9 - k + 1);
            countDistinct += ways;
        }

        // numbers with exactly L digits, <= n
        vector<bool> used(10, false);
        for (int i = 0; i < L; i++) {
            int d = s[i] - '0';
            int start = (i == 0) ? 1 : 0;
            for (int digit = start; digit < d; digit++) {
                if (used[digit]) continue;
                int remaining = L - i - 1;
                long long avail = 10 - (i + 1); // digits left to choose from
                long long ways = 1;
                for (int k = 0; k < remaining; k++) ways *= (avail - k);
                countDistinct += ways;
            }
            if (used[d]) break;
            used[d] = true;
            if (i == L - 1) countDistinct++; // n itself has all distinct digits
        }

        return (int)(n - countDistinct);
    }
};
