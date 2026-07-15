// @leetcode id=1737 questionId=1859 slug=change-minimum-characters-to-satisfy-one-of-three-conditions lang=cpp site=leetcode.com title="Change Minimum Characters to Satisfy One of Three Conditions"
class Solution {
public:
    int minCharacters(string a, string b) {
        int cntA[26] = {0}, cntB[26] = {0};
        for (char c : a) cntA[c - 'a']++;
        for (char c : b) cntB[c - 'a']++;

        int prefixA[27] = {0}, prefixB[27] = {0};
        for (int i = 0; i < 26; i++) {
            prefixA[i + 1] = prefixA[i] + cntA[i];
            prefixB[i + 1] = prefixB[i] + cntB[i];
        }

        int n = a.size(), m = b.size();
        int best = INT_MAX;

        // condition 3: both single same letter
        for (int c = 0; c < 26; c++) {
            best = min(best, (n - cntA[c]) + (m - cntB[c]));
        }

        // condition 1/2: split at boundary k (letters 0..k-1 vs k..25)
        for (int k = 1; k <= 25; k++) {
            int costAless = (n - prefixA[k]) + prefixB[k];
            int costBless = (m - prefixB[k]) + prefixA[k];
            best = min(best, min(costAless, costBless));
        }

        return best;
    }
};
