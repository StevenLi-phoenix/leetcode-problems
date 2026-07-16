// @leetcode id=2531 questionId=2615 slug=make-number-of-distinct-characters-equal lang=cpp site=leetcode.com title="Make Number of Distinct Characters Equal"
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (char c : word1) cnt1[c - 'a']++;
        for (char c : word2) cnt2[c - 'a']++;

        int distinct1 = 0, distinct2 = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] > 0) distinct1++;
            if (cnt2[i] > 0) distinct2++;
        }

        for (int c1 = 0; c1 < 26; c1++) {
            if (cnt1[c1] == 0) continue;
            for (int c2 = 0; c2 < 26; c2++) {
                if (cnt2[c2] == 0) continue;

                int newDistinct1 = distinct1;
                int newDistinct2 = distinct2;

                if (c1 == c2) {
                    // no change
                } else {
                    if (cnt1[c1] == 1) newDistinct1--;
                    if (cnt1[c2] == 0) newDistinct1++;

                    if (cnt2[c2] == 1) newDistinct2--;
                    if (cnt2[c1] == 0) newDistinct2++;
                }

                if (newDistinct1 == newDistinct2) return true;
            }
        }
        return false;
    }
};
