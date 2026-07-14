// @leetcode id=3407 questionId=3684 slug=substring-matching-pattern lang=cpp site=leetcode.com title="Substring Matching Pattern"
class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find('*');
        string prefix = p.substr(0, star);
        string suffix = p.substr(star + 1);

        int n = s.size();
        for (int i = 0; i + (int)prefix.size() <= n; i++) {
            if (s.compare(i, prefix.size(), prefix) != 0) continue;
            int afterPrefix = i + prefix.size();
            for (int j = afterPrefix; j + (int)suffix.size() <= n; j++) {
                if (s.compare(j, suffix.size(), suffix) == 0) return true;
            }
        }
        return false;
    }
};
