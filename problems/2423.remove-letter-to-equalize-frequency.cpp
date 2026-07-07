// @leetcode id=2423 questionId=2532 slug=remove-letter-to-equalize-frequency lang=cpp site=leetcode.com title="Remove Letter To Equalize Frequency"
class Solution {
public:
    bool equalFrequency(string word) {
        for (int i = 0; i < (int)word.size(); ++i) {
            int cnt[26] = {0};
            for (int j = 0; j < (int)word.size(); ++j) {
                if (j == i) continue;
                ++cnt[word[j] - 'a'];
            }

            int freq = -1;
            bool ok = true;
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] == 0) continue;
                if (freq == -1) freq = cnt[c];
                else if (cnt[c] != freq) { ok = false; break; }
            }
            if (ok) return true;
        }
        return false;
    }
};
