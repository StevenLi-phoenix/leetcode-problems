// @leetcode id=3361 questionId=3591 slug=shift-distance-between-two-strings lang=cpp site=leetcode.com title="Shift Distance Between Two Strings"
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        // Precompute, for each starting letter, the cost to reach every
        // other letter via forward-only shifts and via backward-only
        // shifts around the 26-letter cycle (each O(26)), then take the
        // cheaper direction per character pair.
        long long forwardCost[26][26], backwardCost[26][26];
        for (int a = 0; a < 26; a++) {
            long long cost = 0;
            int cur = a;
            for (int step = 0; step < 26; step++) {
                forwardCost[a][cur] = cost;
                cost += nextCost[cur];
                cur = (cur + 1) % 26;
            }
        }
        for (int a = 0; a < 26; a++) {
            long long cost = 0;
            int cur = a;
            for (int step = 0; step < 26; step++) {
                backwardCost[a][cur] = cost;
                cost += previousCost[cur];
                cur = (cur - 1 + 26) % 26;
            }
        }

        long long total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int a = s[i] - 'a', b = t[i] - 'a';
            total += min(forwardCost[a][b], backwardCost[a][b]);
        }
        return total;
    }
};
