// @leetcode id=1734 questionId=1835 slug=decode-xored-permutation lang=cpp site=leetcode.com title="Decode XORed Permutation"
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int totalXor = 0;
        for (int i = 1; i <= n; i++) totalXor ^= i;

        int oddEncodedXor = 0;
        for (int i = 1; i < (int)encoded.size(); i += 2) oddEncodedXor ^= encoded[i];

        vector<int> perm(n);
        perm[0] = totalXor ^ oddEncodedXor;
        for (int i = 1; i < n; i++) perm[i] = perm[i - 1] ^ encoded[i - 1];
        return perm;
    }
};
