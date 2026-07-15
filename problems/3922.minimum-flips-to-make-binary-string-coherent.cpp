// @leetcode id=3922 questionId=4131 slug=minimum-flips-to-make-binary-string-coherent lang=cpp site=leetcode.com title="Minimum Flips to Make Binary String Coherent"
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) if (c == '1') totalOnes++;
        int totalZeros = n - totalOnes;

        int costA = totalOnes;           // all zeros
        int costC = totalZeros;          // all ones
        int costB = (totalOnes >= 1) ? totalOnes - 1 : 1; // exactly one '1'

        int best = min({costA, costC, costB});

        if (n >= 2) {
            int costD = (s[0] != '1') + (s[n - 1] != '1');
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == '1') costD++;
            }
            best = min(best, costD);
        }

        return best;
    }
};
