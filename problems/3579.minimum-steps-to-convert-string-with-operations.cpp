// @leetcode id=3579 questionId=3866 slug=minimum-steps-to-convert-string-with-operations lang=cpp site=leetcode.com title="Minimum Steps to Convert String with Operations"
class Solution {
public:
    int costFromCounts(int cnt[26][26]) {
        int mismatch = 0, savings = 0;
        for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
                if (a == b) continue;
                mismatch += cnt[a][b];
            }
        }
        for (int a = 0; a < 26; a++) {
            for (int b = a + 1; b < 26; b++) {
                savings += min(cnt[a][b], cnt[b][a]);
            }
        }
        return mismatch - savings;
    }

    int costNoReverse(const string& w1, const string& w2, int l, int r) {
        int cnt[26][26] = {0};
        for (int i = l; i <= r; i++) {
            int a = w1[i] - 'a', b = w2[i] - 'a';
            if (a != b) cnt[a][b]++;
        }
        return costFromCounts(cnt);
    }

    int costReverse(const string& w1, const string& w2, int l, int r) {
        int cnt[26][26] = {0};
        int len = r - l + 1;
        for (int k = 0; k < len; k++) {
            int a = w1[r - k] - 'a', b = w2[l + k] - 'a';
            if (a != b) cnt[a][b]++;
        }
        return 1 + costFromCounts(cnt);
    }

    int minOperations(string word1, string word2) {
        int n = word1.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] == INT_MAX) continue;
                int c1 = costNoReverse(word1, word2, j, i - 1);
                int c2 = costReverse(word1, word2, j, i - 1);
                int c = min(c1, c2);
                dp[i] = min(dp[i], dp[j] + c);
            }
        }

        return dp[n];
    }
};
