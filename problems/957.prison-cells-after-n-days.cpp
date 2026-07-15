// @leetcode id=957 questionId=994 slug=prison-cells-after-n-days lang=cpp site=leetcode.com title="Prison Cells After N Days"
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        auto nextDay = [](vector<int>& c) {
            vector<int> next(8, 0);
            for (int i = 1; i < 7; i++) {
                next[i] = (c[i - 1] == c[i + 1]) ? 1 : 0;
            }
            return next;
        };

        unordered_map<string, int> seen;
        vector<int> cur = cells;
        int day = 0;
        while (day < n) {
            string key(cur.begin(), cur.end());
            if (seen.count(key)) {
                int cycleLen = day - seen[key];
                int remaining = (n - day) % cycleLen;
                for (int i = 0; i < remaining; i++) cur = nextDay(cur);
                return cur;
            }
            seen[key] = day;
            cur = nextDay(cur);
            day++;
        }
        return cur;
    }
};
