// @leetcode id=2801 questionId=2921 slug=count-stepping-numbers-in-range lang=cpp site=leetcode.com title="Count Stepping Numbers in Range"
class Solution {
public:
    static const long long MOD = 1000000007;
    string digits;
    long long memo[105][10][2][2];
    bool visited[105][10][2][2];

    long long dfs(int pos, int lastDigit, bool tight, bool started) {
        if (pos == (int)digits.size()) return started ? 1 : 0;

        if (visited[pos][lastDigit][tight][started]) return memo[pos][lastDigit][tight][started];
        visited[pos][lastDigit][tight][started] = true;

        int limit = tight ? (digits[pos] - '0') : 9;
        long long total = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            if (!started) {
                if (d == 0) {
                    total = (total + dfs(pos + 1, 0, newTight, false)) % MOD;
                } else {
                    total = (total + dfs(pos + 1, d, newTight, true)) % MOD;
                }
            } else {
                if (abs(d - lastDigit) == 1) {
                    total = (total + dfs(pos + 1, d, newTight, true)) % MOD;
                }
            }
        }

        memo[pos][lastDigit][tight][started] = total;
        return total;
    }

    long long countUpTo(const string& numStr) {
        if (numStr == "-1" || numStr.empty()) return 0;
        digits = numStr;
        memset(visited, 0, sizeof(visited));
        return dfs(0, 0, true, false);
    }

    string decrement(string s) {
        int n = s.size();
        int i = n - 1;
        while (i >= 0 && s[i] == '0') { s[i] = '9'; i--; }
        if (i < 0) return "-1";
        s[i]--;
        int start = 0;
        while (start < (int)s.size() - 1 && s[start] == '0') start++;
        return s.substr(start);
    }

    int countSteppingNumbers(string low, string high) {
        long long high_count = countUpTo(high);
        string lowMinus1 = decrement(low);
        long long low_count = countUpTo(lowMinus1);
        long long answer = (high_count - low_count + MOD) % MOD;
        return (int)answer;
    }
};
