// @leetcode id=2156 questionId=2275 slug=find-substring-with-given-hash-value lang=cpp site=leetcode.com title="Find Substring With Given Hash Value"
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long p = power, m = modulo;

        long long pk = 1; // p^k mod m
        for (int i = 0; i < k; i++) pk = (pk * p) % m;

        auto val = [&](int i) { return (long long)(s[i] - 'a' + 1); };

        long long h = 0;
        for (int i = n - 1; i >= n - k; i--) {
            h = (h * p + val(i)) % m;
        }

        int resultIdx = -1;
        if (h == hashValue) resultIdx = n - k;

        for (int i = n - k - 1; i >= 0; i--) {
            h = ((h * p) % m + val(i)) % m;
            h = ((h - (val(i + k) * pk) % m) % m + m) % m;
            if (h == hashValue) resultIdx = i;
        }

        return s.substr(resultIdx, k);
    }
};
