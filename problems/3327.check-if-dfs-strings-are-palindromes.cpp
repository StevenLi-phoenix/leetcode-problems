// @leetcode id=3327 questionId=3603 slug=check-if-dfs-strings-are-palindromes lang=cpp site=leetcode.com title="Check if DFS Strings Are Palindromes"
class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) children[parent[i]].push_back(i);

        vector<int> start(n), finish(n);
        string flat;
        flat.reserve(n);
        {
            stack<pair<int, int>> st;
            st.push({0, 0});
            while (!st.empty()) {
                auto [node, idx] = st.top();
                st.pop();
                if (idx == 0) start[node] = flat.size();
                if (idx < (int)children[node].size()) {
                    st.push({node, idx + 1});
                    st.push({children[node][idx], 0});
                } else {
                    flat.push_back(s[node]);
                    finish[node] = flat.size();
                }
            }
        }

        string rev(flat.rbegin(), flat.rend());

        const long long MOD1 = 1000000007, B1 = 131;
        const long long MOD2 = 998244353, B2 = 137;

        vector<long long> h1(n + 1), h2(n + 1), rh1(n + 1), rh2(n + 1);
        vector<long long> p1(n + 1), p2(n + 1);
        p1[0] = p2[0] = 1;
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = (h1[i] * B1 + flat[i]) % MOD1;
            h2[i + 1] = (h2[i] * B2 + flat[i]) % MOD2;
            rh1[i + 1] = (rh1[i] * B1 + rev[i]) % MOD1;
            rh2[i + 1] = (rh2[i] * B2 + rev[i]) % MOD2;
            p1[i + 1] = (p1[i] * B1) % MOD1;
            p2[i + 1] = (p2[i] * B2) % MOD2;
        }

        auto getHash = [&](vector<long long>& h, vector<long long>& p, long long mod, int l, int r) {
            long long res = (h[r] - h[l] * p[r - l]) % mod;
            if (res < 0) res += mod;
            return res;
        };

        vector<bool> ans(n);
        for (int i = 0; i < n; ++i) {
            int l = start[i], r = finish[i];
            int rl = n - r, rr = n - l;
            bool ok1 = getHash(h1, p1, MOD1, l, r) == getHash(rh1, p1, MOD1, rl, rr);
            bool ok2 = getHash(h2, p2, MOD2, l, r) == getHash(rh2, p2, MOD2, rl, rr);
            ans[i] = ok1 && ok2;
        }
        return ans;
    }
};
