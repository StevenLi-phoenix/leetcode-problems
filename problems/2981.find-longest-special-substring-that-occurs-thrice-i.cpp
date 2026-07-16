// @leetcode id=2981 questionId=3267 slug=find-longest-special-substring-that-occurs-thrice-i lang=cpp site=leetcode.com title="Find Longest Special Substring That Occurs Thrice I"
class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> runs(26);
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            runs[s[i] - 'a'].push_back(j - i);
            i = j;
        }

        int best = -1;
        for (int c = 0; c < 26; c++) {
            if (runs[c].empty()) continue;
            int maxRun = *max_element(runs[c].begin(), runs[c].end());
            for (int len = maxRun; len >= 1; len--) {
                long long total = 0;
                for (int r : runs[c]) total += max(0, r - len + 1);
                if (total >= 3) {
                    best = max(best, len);
                    break;
                }
            }
        }
        return best;
    }
};
