// @leetcode id=3170 questionId=3445 slug=lexicographically-minimum-string-after-removing-stars lang=cpp site=leetcode.com title="Lexicographically Minimum String After Removing Stars"
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        // 26 stacks for each character
        vector<vector<int>> stacks(26);
        vector<bool> removed(n, false);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                removed[i] = true;
                // Find smallest character stack that is non-empty
                for (int c = 0; c < 26; c++) {
                    if (!stacks[c].empty()) {
                        removed[stacks[c].back()] = true;
                        stacks[c].pop_back();
                        break;
                    }
                }
            } else {
                stacks[s[i] - 'a'].push_back(i);
            }
        }
        
        string result;
        for (int i = 0; i < n; i++) {
            if (!removed[i] && s[i] != '*') {
                result += s[i];
            }
        }
        return result;
    }
};
