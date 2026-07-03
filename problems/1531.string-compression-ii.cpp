// @leetcode id=1531 questionId=1637 slug=string-compression-ii lang=cpp site=leetcode.com title="String Compression II"
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        this->s = s;
        memo.assign(n, vector<int>(k + 1, -1));
        return solve(0, k);
    }

private:
    int n;
    string s;
    vector<vector<int>> memo;

    int encLen(int count) {
        if (count == 0) return 0;
        if (count == 1) return 1;
        if (count < 10) return 2;
        if (count < 100) return 3;
        return 4;
    }

    int solve(int i, int k) {
        if (i == n) return 0;
        if (memo[i][k] != -1) return memo[i][k];

        int res = INT_MAX;
        if (k > 0) res = solve(i + 1, k - 1);

        int cnt = 0, del = 0;
        for (int j = i; j < n && del <= k; ++j) {
            if (s[j] == s[i]) ++cnt;
            else ++del;
            if (del <= k) {
                res = min(res, encLen(cnt) + solve(j + 1, k - del));
            }
        }

        return memo[i][k] = res;
    }
};
