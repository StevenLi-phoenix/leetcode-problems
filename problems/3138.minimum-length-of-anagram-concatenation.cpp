// @leetcode id=3138 questionId=3395 slug=minimum-length-of-anagram-concatenation lang=cpp site=leetcode.com title="Minimum Length of Anagram Concatenation"
class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        for (int len = 1; len <= n; ++len) {
            if (n % len != 0) continue;
            if (isValid(s, len)) return len;
        }
        return n;
    }

private:
    bool isValid(const string& s, int len) {
        int n = s.size();
        int base[26] = {0};
        for (int i = 0; i < len; ++i) base[s[i] - 'a']++;

        for (int start = len; start < n; start += len) {
            int cnt[26] = {0};
            for (int i = 0; i < len; ++i) cnt[s[start + i] - 'a']++;
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] != base[c]) return false;
            }
        }
        return true;
    }
};
