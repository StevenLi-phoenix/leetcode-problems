// @leetcode id=1763 questionId=1873 slug=longest-nice-substring lang=cpp site=leetcode.com title="Longest Nice Substring"
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int maxStart = 0;

        for (int i = 0; i < n; i++) {
            set<char> chars;
            for (int j = i; j < n; j++) {
                chars.insert(s[j]);

                bool isNice = true;
                for (char c : chars) {
                    char other = isupper(c) ? tolower(c) : toupper(c);
                    if (chars.find(other) == chars.end()) {
                        isNice = false;
                        break;
                    }
                }

                if (isNice && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    maxStart = i;
                }
            }
        }

        return s.substr(maxStart, maxLen);
    }
};
