// @leetcode id=2983 questionId=3203 slug=palindrome-rearrangement-queries lang=cpp site=leetcode.com title="Palindrome Rearrangement Queries"
class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int half = n / 2;

        vector<array<int, 26>> pre(n + 1);
        pre[0].fill(0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i];
            pre[i + 1][s[i] - 'a']++;
        }
        auto freqRange = [&](int l, int r) -> array<int, 26> {
            array<int, 26> res{};
            if (l > r) return res;
            for (int c = 0; c < 26; ++c) res[c] = pre[r + 1][c] - pre[l][c];
            return res;
        };

        vector<int> mismatchPrefix(half + 1, 0);
        for (int i = 0; i < half; ++i) {
            mismatchPrefix[i + 1] = mismatchPrefix[i] + (s[i] != s[n - 1 - i] ? 1 : 0);
        }
        auto mismatchRange = [&](int l, int r) {
            if (l > r) return 0;
            return mismatchPrefix[r + 1] - mismatchPrefix[l];
        };

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int a = q[0], b = q[1], c = q[2], d = q[3];
            int el = n - 1 - d, er = n - 1 - c;

            vector<int> bp = {0, a, b + 1, el, er + 1, half};
            sort(bp.begin(), bp.end());
            bp.erase(unique(bp.begin(), bp.end()), bp.end());

            array<int, 26> forcedAB{}, forcedCD{};
            int mismatchCount = 0;
            bool ok = true;

            for (size_t k = 0; k + 1 < bp.size(); ++k) {
                int segL = bp[k], segR = bp[k + 1];
                if (segL >= segR) continue;
                bool inAB = (segL >= a && segL <= b);
                bool inE = (segL >= el && segL <= er);
                if (!inAB && !inE) {
                    mismatchCount += mismatchRange(segL, segR - 1);
                } else if (inAB && !inE) {
                    int mirL = n - 1 - (segR - 1), mirR = n - 1 - segL;
                    auto f = freqRange(mirL, mirR);
                    for (int ch = 0; ch < 26; ++ch) forcedAB[ch] += f[ch];
                } else if (!inAB && inE) {
                    auto f = freqRange(segL, segR - 1);
                    for (int ch = 0; ch < 26; ++ch) forcedCD[ch] += f[ch];
                }
                // both true: free-free, no forced demand
            }

            if (mismatchCount > 0) ok = false;

            if (ok) {
                auto ABtotal = freqRange(a, b);
                auto CDtotal = freqRange(c, d);
                for (int ch = 0; ch < 26 && ok; ++ch) {
                    if (forcedAB[ch] > ABtotal[ch] || forcedCD[ch] > CDtotal[ch]) ok = false;
                }
                if (ok) {
                    for (int ch = 0; ch < 26 && ok; ++ch) {
                        if (ABtotal[ch] - forcedAB[ch] != CDtotal[ch] - forcedCD[ch]) ok = false;
                    }
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};
