// @leetcode id=68 questionId=68 slug=text-justification lang=cpp site=leetcode.com title="Text Justification"
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLen = 0;
            while (j < n && lineLen + (int)words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                ++j;
            }

            int numWords = j - i;
            string line;

            if (j == n || numWords == 1) {
                // last line or single word: left-justify
                for (int k = i; k < j; ++k) {
                    if (k > i) line += ' ';
                    line += words[k];
                }
                while ((int)line.size() < maxWidth) line += ' ';
            } else {
                int totalSpaces = maxWidth - lineLen;
                int gaps = numWords - 1;
                int baseSpace = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = baseSpace + (k - i < extra ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }
        return result;
    }
};
