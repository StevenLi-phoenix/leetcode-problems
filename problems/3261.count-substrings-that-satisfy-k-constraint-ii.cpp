// @leetcode id=3261 questionId=3546 slug=count-substrings-that-satisfy-k-constraint-ii lang=cpp site=leetcode.com title="Count Substrings That Satisfy K-Constraint II"
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> g(n);
        int cnt0 = 0, cnt1 = 0, j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n) {
                int nc0 = cnt0 + (s[j] == '0');
                int nc1 = cnt1 + (s[j] == '1');
                if (min(nc0, nc1) <= k) { cnt0 = nc0; cnt1 = nc1; j++; }
                else break;
            }
            g[i] = j;
            if (s[i] == '0') cnt0--; else cnt1--;
        }

        vector<long long> prefixG(n + 1, 0), prefixI(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixG[i + 1] = prefixG[i] + g[i];
            prefixI[i + 1] = prefixI[i] + i;
        }

        vector<long long> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int R1 = r + 1;

            int lo = l, hi = r + 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (g[mid] <= R1) lo = mid + 1;
                else hi = mid;
            }
            int t = lo - 1;

            long long sumFull = (prefixG[t + 1] - prefixG[l]) - (prefixI[t + 1] - prefixI[l]);
            long long capCount = r - t;
            long long sumCapped = capCount * (capCount + 1) / 2;

            answer.push_back(sumFull + sumCapped);
        }

        return answer;
    }
};
