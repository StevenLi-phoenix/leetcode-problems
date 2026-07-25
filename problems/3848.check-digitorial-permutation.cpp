// @leetcode id=3848 questionId=4226 slug=check-digitorial-permutation lang=cpp site=leetcode.com title="Check Digitorial Permutation"
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

        string s = to_string(n);
        long long sum = 0;
        for (char c : s) {
            sum += fact[c - '0'];
        }

        string t = to_string(sum);
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
