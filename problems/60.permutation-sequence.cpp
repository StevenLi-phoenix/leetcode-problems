// @leetcode id=60 questionId=60 slug=permutation-sequence lang=cpp site=leetcode.com title="Permutation Sequence"
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

        vector<int> digits;
        for (int i = 1; i <= n; ++i) digits.push_back(i);

        --k; // switch to 0-indexed
        string result;
        for (int i = n; i >= 1; --i) {
            int idx = k / fact[i - 1];
            k %= fact[i - 1];
            result += ('0' + digits[idx]);
            digits.erase(digits.begin() + idx);
        }
        return result;
    }
};
