// @leetcode id=2047 questionId=2173 slug=number-of-valid-words-in-a-sentence lang=cpp site=leetcode.com title="Number of Valid Words in a Sentence"
class Solution {
public:
    int countValidWords(string sentence) {
        auto isValid = [](const string& tok) {
            int hyphens = 0, puncts = 0;
            int n = tok.size();
            for (int i = 0; i < n; i++) {
                char c = tok[i];
                if (isdigit((unsigned char)c)) return false;
                if (c == '-') {
                    hyphens++;
                    if (hyphens > 1) return false;
                    if (i == 0 || i == n - 1 ||
                        !islower((unsigned char)tok[i - 1]) ||
                        !islower((unsigned char)tok[i + 1])) return false;
                } else if (c == '!' || c == '.' || c == ',') {
                    puncts++;
                    if (puncts > 1) return false;
                    if (i != n - 1) return false;
                } else if (!islower((unsigned char)c)) {
                    return false;
                }
            }
            return true;
        };

        stringstream ss(sentence);
        string tok;
        int count = 0;
        while (ss >> tok) {
            if (isValid(tok)) count++;
        }
        return count;
    }
};
