// @leetcode id=3297 questionId=3573 slug=count-substrings-that-can-be-rearranged-to-contain-a-string-i lang=cpp site=leetcode.com title="Count Substrings That Can Be Rearranged to Contain a String I"
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int need[26] = {0};
        for (char c : word2) need[c - 'a']++;
        int missing = 0;
        for (int i = 0; i < 26; i++) if (need[i] > 0) missing++;

        int n = word1.size();
        long long result = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            int c = word1[right] - 'a';
            need[c]--;
            if (need[c] == 0) missing--;

            while (missing == 0) {
                result += n - right;
                int lc = word1[left] - 'a';
                need[lc]++;
                if (need[lc] == 1) missing++;
                left++;
            }
        }
        return result;
    }
};
