// @leetcode id=3853 questionId=4013 slug=merge-close-characters lang=cpp site=leetcode.com title="Merge Close Characters"
class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool merged = true;
        while (merged) {
            merged = false;
            int n = s.size();
            for (int i = 0; i < n && !merged; i++) {
                for (int j = i + 1; j < n && j - i <= k; j++) {
                    if (s[i] == s[j]) {
                        s.erase(s.begin() + j);
                        merged = true;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
