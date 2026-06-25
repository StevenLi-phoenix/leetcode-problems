// @leetcode id=784 questionId=800 slug=letter-case-permutation lang=cpp site=leetcode.com title="Letter Case Permutation"
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;

        function<void(int, string)> backtrack = [&](int idx, string current) {
            if (idx == s.length()) {
                result.push_back(current);
                return;
            }

            if (isdigit(s[idx])) {
                backtrack(idx + 1, current + s[idx]);
            } else {
                backtrack(idx + 1, current + (char)tolower(s[idx]));
                backtrack(idx + 1, current + (char)toupper(s[idx]));
            }
        };

        backtrack(0, "");
        return result;
    }
};
