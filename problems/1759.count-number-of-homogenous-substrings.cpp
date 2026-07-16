// @leetcode id=1759 questionId=1885 slug=count-number-of-homogenous-substrings lang=cpp site=leetcode.com title="Count Number of Homogenous Substrings"
class Solution {
public:
    int countHomogenous(string s) {
        const long long MOD = 1e9 + 7;
        long long total = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            long long len = j - i;
            total = (total + len * (len + 1) / 2) % MOD;
            i = j;
        }
        return (int)total;
    }
};
