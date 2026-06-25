// @leetcode id=779 questionId=795 slug=k-th-symbol-in-grammar lang=cpp site=leetcode.com title="K-th Symbol in Grammar"
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;

        long long len = 1LL << (n - 2);

        if (k <= len) {
            return kthGrammar(n - 1, k);
        } else {
            return 1 - kthGrammar(n - 1, k - len);
        }
    }
};
