// @leetcode id=1001 questionId=1043 slug=grid-illumination lang=cpp site=leetcode.com title="Grid Illumination"
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<long long,int> rowCnt, colCnt, diag1Cnt, diag2Cnt;
        unordered_set<long long> lampSet;

        auto encode = [&](int r, int c) { return (long long)r * (2LL * n) + c; };

        for (auto& l : lamps) {
            int r = l[0], c = l[1];
            long long key = encode(r, c);
            if (lampSet.count(key)) continue;
            lampSet.insert(key);
            rowCnt[r]++;
            colCnt[c]++;
            diag1Cnt[r - c]++;
            diag2Cnt[r + c]++;
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int r = q[0], c = q[1];
            bool lit = (rowCnt.count(r) && rowCnt[r] > 0) ||
                       (colCnt.count(c) && colCnt[c] > 0) ||
                       (diag1Cnt.count(r - c) && diag1Cnt[r - c] > 0) ||
                       (diag2Cnt.count(r + c) && diag2Cnt[r + c] > 0);
            answer.push_back(lit ? 1 : 0);

            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    long long key = encode(nr, nc);
                    if (lampSet.count(key)) {
                        lampSet.erase(key);
                        rowCnt[nr]--;
                        colCnt[nc]--;
                        diag1Cnt[nr - nc]--;
                        diag2Cnt[nr + nc]--;
                    }
                }
            }
        }

        return answer;
    }
};
