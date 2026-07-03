// @leetcode id=3501 questionId=3804 slug=maximize-active-section-with-trade-ii lang=cpp site=leetcode.com title="Maximize Active Section with Trade II"
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<char> rc;
        vector<int> rlen, rstart, rend;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            rc.push_back(s[i]);
            rstart.push_back(i);
            rend.push_back(j - 1);
            rlen.push_back(j - i);
            i = j;
        }
        int R = rc.size();

        vector<int> pre(n + 1, 0);
        for (int k = 0; k < n; k++) pre[k + 1] = pre[k] + (s[k] == '1');

        // G[i] = gain of interior 1-run at run-index i, using full (unclipped) neighbor run lengths.
        vector<long long> G(R, -1);
        for (int k = 1; k + 1 < R; k++) {
            if (rc[k] == '1') G[k] = (long long)rlen[k - 1] + rlen[k + 1];
        }

        int LOG = 1;
        while ((1 << LOG) < max(R, 1)) LOG++;
        LOG++;
        vector<vector<long long>> sp(LOG, vector<long long>(R, -1));
        if (R > 0) sp[0] = G;
        for (int k = 1; k < LOG; k++) {
            for (int idx = 0; idx + (1 << k) <= R; idx++) {
                sp[k][idx] = max(sp[k - 1][idx], sp[k - 1][idx + (1 << (k - 1))]);
            }
        }
        auto rangeMax = [&](int l, int r) -> long long {
            if (l > r) return -1;
            int k = 0;
            while ((1 << (k + 1)) <= (r - l + 1)) k++;
            return max(sp[k][l], sp[k][r - (1 << k) + 1]);
        };

        auto findRun = [&](int pos) -> int {
            int lo = 0, hi = R - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (rstart[mid] <= pos) lo = mid;
                else hi = mid - 1;
            }
            return lo;
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int idxL = findRun(l), idxR = findRun(r);
            long long ones = pre[r + 1] - pre[l];
            long long bestGain = -1;

            if (idxL != idxR) {
                bestGain = max(bestGain, rangeMax(idxL + 2, idxR - 2));

                int i1 = idxL + 1;
                if (i1 < idxR && rc[i1] == '1') {
                    long long leftZero = rend[idxL] - l + 1;
                    long long rightZero = (i1 + 1 == idxR) ? (r - rstart[idxR] + 1) : rlen[i1 + 1];
                    bestGain = max(bestGain, leftZero + rightZero);
                }

                int i2 = idxR - 1;
                if (i2 > idxL && rc[i2] == '1') {
                    long long rightZero = r - rstart[idxR] + 1;
                    long long leftZero = (i2 - 1 == idxL) ? (rend[idxL] - l + 1) : rlen[i2 - 1];
                    bestGain = max(bestGain, leftZero + rightZero);
                }
            }

            ans.push_back((int)(ones + max(0LL, bestGain)));
        }
        return ans;
    }
};
