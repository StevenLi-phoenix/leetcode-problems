// @leetcode id=522 questionId=522 slug=longest-uncommon-subsequence-ii lang=cpp site=leetcode.com title="Longest Uncommon Subsequence II"
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int best = -1;
        for (int i = 0; i < n; i++) {
            bool isUncommon = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            if (isUncommon) best = max(best, (int)strs[i].size());
        }
        return best;
    }

private:
    bool isSubsequence(const string& s, const string& t) {
        size_t i = 0;
        for (char c : t) {
            if (i < s.size() && s[i] == c) i++;
        }
        return i == s.size();
    }
};
