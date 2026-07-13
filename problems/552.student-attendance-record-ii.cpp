// @leetcode id=552 questionId=552 slug=student-attendance-record-ii lang=cpp site=leetcode.com title="Student Attendance Record II"
class Solution {
public:
    int checkRecord(int n) {
        const long long MOD = 1e9 + 7;
        // dp[absences][trailingLates]
        vector<vector<long long>> dp(2, vector<long long>(3, 0));
        dp[0][0] = 1;

        for (int day = 0; day < n; day++) {
            vector<vector<long long>> next(2, vector<long long>(3, 0));
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) {
                    long long val = dp[a][l];
                    if (val == 0) continue;
                    // Present
                    next[a][0] = (next[a][0] + val) % MOD;
                    // Absent
                    if (a == 0) next[a + 1][0] = (next[a + 1][0] + val) % MOD;
                    // Late
                    if (l < 2) next[a][l + 1] = (next[a][l + 1] + val) % MOD;
                }
            }
            dp = next;
        }

        long long total = 0;
        for (int a = 0; a < 2; a++)
            for (int l = 0; l < 3; l++)
                total = (total + dp[a][l]) % MOD;
        return (int)total;
    }
};
