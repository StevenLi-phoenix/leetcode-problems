// @leetcode id=1400 questionId=1502 slug=construct-k-palindrome-strings lang=cpp site=leetcode.com title="Construct K Palindrome Strings"
class Solution {
public:
    bool canConstruct(string s, int k) {
        if ((int)s.size() < k) return false;
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        int oddCount = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) oddCount++;
        }
        return oddCount <= k;
    }
};
