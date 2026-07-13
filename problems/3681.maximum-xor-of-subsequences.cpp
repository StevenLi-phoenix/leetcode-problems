// @leetcode id=3681 questionId=3990 slug=maximum-xor-of-subsequences lang=cpp site=leetcode.com title="Maximum XOR of Subsequences"
class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        // An element included in both subsequences cancels out of X^Y, in
        // neither contributes 0, and in exactly one contributes itself —
        // so X^Y ranges exactly over all subset-XORs of nums. Build a
        // linear basis (over GF(2)) and greedily combine it to maximize.
        vector<int> basis(30, 0);
        for (int v : nums) {
            for (int b = 29; b >= 0; b--) {
                if (!((v >> b) & 1)) continue;
                if (basis[b] == 0) {
                    basis[b] = v;
                    break;
                }
                v ^= basis[b];
            }
        }

        int result = 0;
        for (int b = 29; b >= 0; b--) {
            if ((result ^ basis[b]) > result) result ^= basis[b];
        }
        return result;
    }
};
