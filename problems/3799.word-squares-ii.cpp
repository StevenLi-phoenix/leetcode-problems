// @leetcode id=3799 questionId=4071 slug=word-squares-ii lang=cpp site=leetcode.com title="Word Squares II"
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> result;

        for (int t = 0; t < n; t++) {
            for (int l = 0; l < n; l++) {
                if (l == t) continue;
                if (words[t][0] != words[l][0]) continue;
                for (int r = 0; r < n; r++) {
                    if (r == t || r == l) continue;
                    if (words[t][3] != words[r][0]) continue;
                    for (int b = 0; b < n; b++) {
                        if (b == t || b == l || b == r) continue;
                        if (words[b][0] != words[l][3]) continue;
                        if (words[b][3] != words[r][3]) continue;
                        result.push_back({words[t], words[l], words[r], words[b]});
                    }
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
