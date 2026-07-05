// @leetcode id=3445 questionId=3761 slug=maximum-difference-between-even-and-odd-frequency-ii lang=cpp site=leetcode.com title="Maximum Difference Between Even and Odd Frequency II"
class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        const int INF = INT_MAX / 2;

        struct FenwickMin {
            vector<int> tree;
            int sz;
            void init(int size) {
                sz = size;
                tree.assign(sz + 2, INT_MAX / 2);
            }
            void update(int pos, int val) {
                for (; pos <= sz + 1; pos += pos & (-pos)) tree[pos] = min(tree[pos], val);
            }
            int query(int pos) {
                int res = INT_MAX / 2;
                for (; pos > 0; pos -= pos & (-pos)) res = min(res, tree[pos]);
                return res;
            }
        };

        int ans = INT_MIN;

        for (int a = 0; a < 5; ++a) {
            for (int b = 0; b < 5; ++b) {
                if (a == b) continue;
                char ca = '0' + a, cb = '0' + b;

                vector<int> prefA(n + 1, 0), prefB(n + 1, 0);
                for (int i = 0; i < n; ++i) {
                    prefA[i + 1] = prefA[i] + (s[i] == ca ? 1 : 0);
                    prefB[i + 1] = prefB[i] + (s[i] == cb ? 1 : 0);
                }

                FenwickMin fw[2][2];
                for (int pa = 0; pa < 2; ++pa)
                    for (int pb = 0; pb < 2; ++pb) fw[pa][pb].init(n + 1);

                for (int i = 0; i <= n; ++i) {
                    int targetJ = i - k;
                    if (targetJ >= 0) {
                        int pa = prefA[targetJ] & 1, pb = prefB[targetJ] & 1;
                        int Dj = prefA[targetJ] - prefB[targetJ];
                        fw[pa][pb].update(prefB[targetJ] + 1, Dj);
                    }
                    if (targetJ >= 0) {
                        int pai = prefA[i] & 1, pbi = prefB[i] & 1;
                        int wantPa = 1 - pai;
                        int minD = fw[wantPa][pbi].query(prefB[i]); // prefB[j] <= prefB[i]-1 => positions [1, prefB[i]]
                        if (minD < INF) {
                            int Di = prefA[i] - prefB[i];
                            ans = max(ans, Di - minD);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
