// @leetcode id=2612 questionId=2726 slug=minimum-reverse-operations lang=cpp site=leetcode.com title="Minimum Reverse Operations"
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> dist(n, -1);
        vector<bool> isBanned(n, false);
        for (int b : banned) isBanned[b] = true;

        set<int> byParity[2];
        for (int i = 0; i < n; i++) {
            if (i != p && !isBanned[i]) byParity[i % 2].insert(i);
        }

        dist[p] = 0;
        queue<int> q;
        q.push(p);

        while (!q.empty()) {
            int i = q.front(); q.pop();
            int L = max(0, i - k + 1);
            int R = min(i, n - k);
            if (L > R) continue;
            int jLow = 2 * L + k - 1 - i;
            int jHigh = 2 * R + k - 1 - i;
            int parity = jLow % 2;
            auto& s = byParity[parity];
            auto it = s.lower_bound(jLow);
            while (it != s.end() && *it <= jHigh) {
                int j = *it;
                dist[j] = dist[i] + 1;
                q.push(j);
                it = s.erase(it);
            }
        }
        return dist;
    }
};
