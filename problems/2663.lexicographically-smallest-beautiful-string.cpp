// @leetcode id=2663 questionId=2687 slug=lexicographically-smallest-beautiful-string lang=cpp site=leetcode.com title="Lexicographically Smallest Beautiful String"
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.length();
        string orig = s;

        for (int i = n - 1; i >= 0; i--) {
            s = orig;
            for (char c = orig[i] + 1; c < 'a' + k; c++) {
                if ((i == 0 || orig[i-1] != c) && (i <= 1 || orig[i-2] != c)) {
                    s[i] = c;
                    bool valid = true;
                    for (int j = i + 1; j < n; j++) {
                        bool found = false;
                        for (char ch = 'a'; ch < 'a' + k; ch++) {
                            if ((j == 0 || s[j-1] != ch) && (j <= 1 || s[j-2] != ch)) {
                                s[j] = ch;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) return s;
                }
            }
        }
        return "";
    }
};
