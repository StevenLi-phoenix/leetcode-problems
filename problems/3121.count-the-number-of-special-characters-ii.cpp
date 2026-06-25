// @leetcode id=3121 questionId=3405 slug=count-the-number-of-special-characters-ii lang=cpp site=leetcode.com title="Count the Number of Special Characters II"
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lastLower[26], firstUpper[26];
        fill(lastLower, lastLower + 26, -1);
        fill(firstUpper, firstUpper + 26, INT_MAX);
        
        for (int i = 0; i < (int)word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLower[c - 'a'] = i;
            } else {
                int idx = c - 'A';
                firstUpper[idx] = min(firstUpper[idx], i);
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != INT_MAX && lastLower[i] < firstUpper[i]) {
                count++;
            }
        }
        return count;
    }
};
