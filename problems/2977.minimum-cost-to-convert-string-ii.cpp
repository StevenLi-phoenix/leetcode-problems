// @leetcode id=2977 questionId=3238 slug=minimum-cost-to-convert-string-ii lang=cpp site=leetcode.com title="Minimum Cost to Convert String II"
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size(), m = original.size();

        // Trie
        vector<array<int,26>> ch(1);
        ch[0].fill(-1);
        vector<int> sid(1, -1); // string ID at each trie node
        int cnt = 0;

        auto ins = [&](const string& s) -> int {
            int u = 0;
            for (char c : s) {
                int ci = c - 'a';
                if (ch[u][ci] == -1) {
                    ch[u][ci] = ch.size();
                    ch.push_back({});
                    ch.back().fill(-1);
                    sid.push_back(-1);
                }
                u = ch[u][ci];
            }
            if (sid[u] == -1) sid[u] = cnt++;
            return sid[u];
        };

        vector<int> oid(m), cid(m);
        for (int i = 0; i < m; i++) {
            oid[i] = ins(original[i]);
            cid[i] = ins(changed[i]);
        }

        // Floyd-Warshall on conversion graph
        int V = cnt;
        const long long INF = 1e18;
        vector<vector<long long>> d(V, vector<long long>(V, INF));
        for (int i = 0; i < V; i++) d[i][i] = 0;
        for (int i = 0; i < m; i++)
            d[oid[i]][cid[i]] = min(d[oid[i]][cid[i]], (long long)cost[i]);

        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++) if (d[i][k] < INF)
                for (int j = 0; j < V; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        // DP
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] >= INF) continue;

            // Characters already match — skip with 0 cost
            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            // Walk trie with source[i..] and target[i..] simultaneously
            int su = 0, tu = 0;
            for (int L = 1; i + L <= n; L++) {
                int sc = source[i + L - 1] - 'a';
                int tc = target[i + L - 1] - 'a';
                if (ch[su][sc] == -1 || ch[tu][tc] == -1) break;
                su = ch[su][sc];
                tu = ch[tu][tc];
                if (sid[su] != -1 && sid[tu] != -1 && d[sid[su]][sid[tu]] < INF)
                    dp[i + L] = min(dp[i + L], dp[i] + d[sid[su]][sid[tu]]);
            }
        }

        return dp[n] >= INF ? -1 : dp[n];
    }
};
