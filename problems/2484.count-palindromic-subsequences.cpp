// @leetcode id=2484 questionId=2577 slug=count-palindromic-subsequences lang=cpp site=leetcode.com title="Count Palindromic Subsequences"
class Solution {
public:
    int countPalindromes(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        long long total = 0;

        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                // L[m] = # pairs i<j<m with s[i]=a, s[j]=b.
                vector<long long> L(n, 0);
                long long countA = 0, countAB = 0;
                for (int m = 0; m < n; m++) {
                    L[m] = countAB;
                    int d = s[m] - '0';
                    if (d == b) countAB += countA;
                    if (d == a) countA++;
                }

                // R[m] = # pairs p<q, both > m, with s[p]=b, s[q]=a.
                vector<long long> R(n, 0);
                long long countA2 = 0, countBA = 0;
                for (int m = n - 1; m >= 0; m--) {
                    R[m] = countBA;
                    int d = s[m] - '0';
                    if (d == b) countBA += countA2;
                    if (d == a) countA2++;
                }

                for (int m = 0; m < n; m++) {
                    total = (total + (L[m] % MOD) * (R[m] % MOD)) % MOD;
                }
            }
        }
        return (int)total;
    }
};
