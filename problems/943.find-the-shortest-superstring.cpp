// @leetcode id=943 questionId=980 slug=find-the-shortest-superstring lang=cpp site=leetcode.com title="Find the Shortest Superstring"
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int maxLen = min(words[i].size(), words[j].size());
                for (int k = maxLen; k > 0; k--) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        int full = 1 << n;
        vector<vector<int>> dp(full, vector<int>(n, 0));
        vector<vector<int>> parent(full, vector<int>(n, -1));

        for (int mask = 1; mask < full; mask++) {
            for (int last = 0; last < n; last++) {
                if (!(mask & (1 << last))) continue;
                int prevMask = mask ^ (1 << last);
                if (prevMask == 0) {
                    dp[mask][last] = 0;
                    continue;
                }
                int best = -1, bestPrev = -1;
                for (int prev = 0; prev < n; prev++) {
                    if (!(prevMask & (1 << prev))) continue;
                    int val = dp[prevMask][prev] + overlap[prev][last];
                    if (val > best) {
                        best = val;
                        bestPrev = prev;
                    }
                }
                dp[mask][last] = best;
                parent[mask][last] = bestPrev;
            }
        }

        int bestLast = 0, bestVal = -1;
        int fullMask = full - 1;
        for (int last = 0; last < n; last++) {
            if (dp[fullMask][last] > bestVal) {
                bestVal = dp[fullMask][last];
                bestLast = last;
            }
        }

        vector<int> order;
        int mask = fullMask, last = bestLast;
        while (last != -1) {
            order.push_back(last);
            int prev = parent[mask][last];
            mask ^= (1 << last);
            last = prev;
        }
        reverse(order.begin(), order.end());

        string result = words[order[0]];
        for (int i = 1; i < (int)order.size(); i++) {
            int ov = overlap[order[i - 1]][order[i]];
            result += words[order[i]].substr(ov);
        }

        return result;
    }
};
