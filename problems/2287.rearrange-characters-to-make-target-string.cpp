// @leetcode id=2287 questionId=2372 slug=rearrange-characters-to-make-target-string lang=cpp site=leetcode.com title="Rearrange Characters to Make Target String"
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int countS[26] = {0}, countT[26] = {0};
        for (char c : s) countS[c - 'a']++;
        for (char c : target) countT[c - 'a']++;

        int best = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (countT[i] > 0) {
                best = min(best, countS[i] / countT[i]);
            }
        }
        return best;
    }
};
