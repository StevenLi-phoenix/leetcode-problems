// @leetcode id=936 questionId=973 slug=stamping-the-sequence lang=cpp site=leetcode.com title="Stamping The Sequence"
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<int> mismatch(n - m + 1, 0);

        for (int i = 0; i <= n - m; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (target[i + j] != stamp[j]) cnt++;
            }
            mismatch[i] = cnt;
        }

        vector<bool> turned(n, false);
        vector<bool> visitedStart(n - m + 1, false);
        queue<int> q;
        for (int i = 0; i <= n - m; i++) {
            if (mismatch[i] == 0) q.push(i);
        }

        vector<int> result;
        int totalTurned = 0;

        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (visitedStart[i]) continue;
            visitedStart[i] = true;
            result.push_back(i);

            for (int j = i; j < i + m; j++) {
                if (!turned[j]) {
                    turned[j] = true;
                    totalTurned++;
                    int sLo = max(0, j - m + 1);
                    int sHi = min(j, n - m);
                    for (int s = sLo; s <= sHi; s++) {
                        if (!visitedStart[s] && target[j] != stamp[j - s]) {
                            mismatch[s]--;
                            if (mismatch[s] == 0) q.push(s);
                        }
                    }
                }
            }
        }

        if (totalTurned != n) return {};

        reverse(result.begin(), result.end());
        return result;
    }
};
