// @leetcode id=3292 questionId=3557 slug=minimum-number-of-valid-strings-to-form-target-ii lang=cpp site=leetcode.com title="Minimum Number of Valid Strings to Form Target II"
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        vector<int> maxLen(n, 0);

        for (auto& w : words) {
            int wl = w.size();
            string s = w + '\x01' + target;
            int sl = s.size();
            vector<int> z(sl, 0);
            int l = 0, r = 0;
            for (int i = 1; i < sl; i++) {
                if (i < r) z[i] = min(r - i, z[i - l]);
                while (i + z[i] < sl && s[z[i]] == s[i + z[i]]) z[i]++;
                if (i + z[i] > r) { l = i; r = i + z[i]; }
            }

            for (int j = 0; j < n; j++) {
                int idx = wl + 1 + j;
                int val = min(z[idx], wl);
                if (val > maxLen[j]) maxLen[j] = val;
            }
        }

        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < n; i++) {
            if (i > curEnd) return -1;
            farthest = max(farthest, i + maxLen[i]);
            if (i == curEnd) {
                if (curEnd >= n) break;
                jumps++;
                curEnd = farthest;
            }
        }

        return curEnd >= n ? jumps : -1;
    }
};
