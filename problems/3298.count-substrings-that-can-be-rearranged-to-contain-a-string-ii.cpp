// @leetcode id=3298 questionId=3572 slug=count-substrings-that-can-be-rearranged-to-contain-a-string-ii lang=cpp site=leetcode.com title="Count Substrings That Can Be Rearranged to Contain a String II"
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int need[26] = {0};
        for (char c : word2) need[c - 'a']++;

        int remaining = 0;
        for (int i = 0; i < 26; i++) if (need[i] > 0) remaining++;

        int cnt[26] = {0};
        long long ans = 0;
        int left = 0;
        int n = word1.size();

        for (int right = 0; right < n; right++) {
            int c = word1[right] - 'a';
            cnt[c]++;
            if (cnt[c] == need[c]) remaining--;

            while (remaining == 0) {
                int lc = word1[left] - 'a';
                if (cnt[lc] == need[lc]) remaining++;
                cnt[lc]--;
                left++;
            }

            ans += left;
        }

        return ans;
    }
};
