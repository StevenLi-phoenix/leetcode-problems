// @leetcode id=1349 questionId=1471 slug=maximum-students-taking-exam lang=cpp site=leetcode.com title="Maximum Students Taking Exam"
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int> avail(m, 0);
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (seats[r][c] == '.') avail[r] |= (1 << c);

        int full = 1 << n;
        vector<int> prev(full, -1), cur(full, -1);
        prev[0] = 0;
        for (int mask = 1; mask < full; mask++) {
            if ((mask & avail[0]) != mask) continue; // must use only available seats
            if (mask & (mask >> 1)) continue; // no horizontally adjacent students
            prev[mask] = __builtin_popcount(mask);
        }

        for (int r = 1; r < m; r++) {
            fill(cur.begin(), cur.end(), -1);
            for (int mask = 0; mask < full; mask++) {
                if ((mask & avail[r]) != mask) continue;
                if (mask & (mask >> 1)) continue;
                for (int pmask = 0; pmask < full; pmask++) {
                    if (prev[pmask] < 0) continue;
                    if (mask & (pmask >> 1)) continue; // upper-left diagonal
                    if (mask & (pmask << 1)) continue; // upper-right diagonal
                    cur[mask] = max(cur[mask], prev[pmask] + __builtin_popcount(mask));
                }
            }
            prev = cur;
        }

        int ans = 0;
        for (int mask = 0; mask < full; mask++) ans = max(ans, prev[mask]);
        return ans;
    }
};
