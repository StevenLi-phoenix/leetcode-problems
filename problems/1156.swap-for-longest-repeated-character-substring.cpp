// @leetcode id=1156 questionId=1261 slug=swap-for-longest-repeated-character-substring lang=cpp site=leetcode.com title="Swap For Longest Repeated Character Substring"
class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        int cnt[26] = {0};
        for (char c : text) cnt[c - 'a']++;

        vector<pair<char, int>> runs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text[j] == text[i]) j++;
            runs.push_back({text[i], j - i});
            i = j;
        }

        int best = 0;
        int m = runs.size();
        for (int k = 0; k < m; k++) {
            int len = runs[k].second;
            int extra = (cnt[runs[k].first - 'a'] > len) ? 1 : 0;
            best = max(best, len + extra);
        }
        for (int k = 0; k + 2 < m; k++) {
            if (runs[k].first == runs[k + 2].first && runs[k + 1].second == 1) {
                int combined = runs[k].second + runs[k + 2].second;
                int extra = (cnt[runs[k].first - 'a'] > combined) ? 1 : 0;
                best = max(best, combined + extra);
            }
        }
        return best;
    }
};
