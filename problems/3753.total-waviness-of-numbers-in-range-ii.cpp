// @leetcode id=3753 questionId=4128 slug=total-waviness-of-numbers-in-range-ii lang=cpp site=leetcode.com title="Total Waviness of Numbers in Range II"
class Solution {
public:
    string S;
    long long cnt_memo[16][2][11][11][2];
    long long ws_memo[16][2][11][11][2];
    bool vis[16][2][11][11][2];
    
    void dp(int pos, bool tight, int prev2, int prev1, bool started,
            long long &cnt_out, long long &ws_out) {
        if (pos == (int)S.size()) {
            cnt_out = 1; ws_out = 0;
            return;
        }
        int ti = tight ? 1 : 0, si = started ? 1 : 0;
        if (vis[pos][ti][prev2][prev1][si]) {
            cnt_out = cnt_memo[pos][ti][prev2][prev1][si];
            ws_out = ws_memo[pos][ti][prev2][prev1][si];
            return;
        }
        vis[pos][ti][prev2][prev1][si] = true;
        
        int limit = tight ? (S[pos] - '0') : 9;
        long long total_cnt = 0, total_ws = 0;
        
        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            long long c, w;
            if (!started && d == 0) {
                dp(pos + 1, newTight, 10, 10, false, c, w);
                total_cnt += c;
                total_ws += w;
            } else {
                long long contrib = 0;
                if (prev1 != 10 && prev2 != 10) {
                    if (prev1 > prev2 && prev1 > d) contrib = 1;
                    else if (prev1 < prev2 && prev1 < d) contrib = 1;
                }
                int np2 = (prev1 == 10) ? 10 : prev1;
                dp(pos + 1, newTight, np2, d, true, c, w);
                total_cnt += c;
                total_ws += w + contrib * c;
            }
        }
        
        cnt_memo[pos][ti][prev2][prev1][si] = total_cnt;
        ws_memo[pos][ti][prev2][prev1][si] = total_ws;
        cnt_out = total_cnt; ws_out = total_ws;
    }
    
    long long solve(long long num) {
        if (num <= 0) return 0;
        S = to_string(num);
        memset(vis, 0, sizeof(vis));
        long long c, w;
        dp(0, true, 10, 10, false, c, w);
        return w;
    }
    
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
