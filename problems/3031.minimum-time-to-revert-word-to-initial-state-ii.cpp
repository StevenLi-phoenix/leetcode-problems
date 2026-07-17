// @leetcode id=3031 questionId=3296 slug=minimum-time-to-revert-word-to-initial-state-ii lang=cpp site=leetcode.com title="Minimum Time to Revert Word to Initial State II"
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> z(n, 0);
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && word[z[i]] == word[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }

        for (int m = k; m < n; m += k) {
            if (z[m] >= n - m) return m / k;
        }

        return (n + k - 1) / k;
    }
};
