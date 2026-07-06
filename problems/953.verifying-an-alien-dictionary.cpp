// @leetcode id=953 questionId=990 slug=verifying-an-alien-dictionary lang=cpp site=leetcode.com title="Verifying an Alien Dictionary"
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int rank[26];
        for (int i = 0; i < 26; ++i) rank[order[i] - 'a'] = i;

        for (int i = 0; i + 1 < (int)words.size(); ++i) {
            const string& a = words[i];
            const string& b = words[i + 1];
            int minLen = min(a.size(), b.size());
            int j = 0;
            while (j < minLen && a[j] == b[j]) ++j;

            if (j == minLen) {
                if (a.size() > b.size()) return false;
            } else if (rank[a[j] - 'a'] > rank[b[j] - 'a']) {
                return false;
            }
        }
        return true;
    }
};
