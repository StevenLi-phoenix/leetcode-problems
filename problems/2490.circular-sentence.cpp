// @leetcode id=2490 questionId=2580 slug=circular-sentence lang=cpp site=leetcode.com title="Circular Sentence"
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        // Check first and last character of the whole sentence
        if (sentence[0] != sentence[n - 1]) return false;
        // Check each space position: char before space and char after space must match
        for (int i = 1; i < n - 1; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) return false;
            }
        }
        return true;
    }
};
