// @leetcode id=3257 questionId=3542 slug=maximum-value-sum-by-placing-three-rooks-ii lang=cpp site=leetcode.com title="Maximum Value Sum by Placing Three Rooks II"
class Solution {
public:
    vector<pair<long long,int>> top3FromColBest(vector<long long>& colBest, int n) {
        vector<pair<long long,int>> best; // up to 3, sorted descending by value
        for (int c = 0; c < n; c++) {
            pair<long long,int> cand = {colBest[c], c};
            best.push_back(cand);
            sort(best.begin(), best.end(), greater<pair<long long,int>>());
            if (best.size() > 3) best.pop_back();
        }
        return best;
    }

    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        const long long NEG = LLONG_MIN / 2;

        vector<vector<pair<long long,int>>> prefixTop(m);
        vector<long long> colBest(n, NEG);
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) colBest[c] = max(colBest[c], (long long)board[r][c]);
            prefixTop[r] = top3FromColBest(colBest, n);
        }

        vector<vector<pair<long long,int>>> suffixTop(m);
        fill(colBest.begin(), colBest.end(), NEG);
        for (int r = m - 1; r >= 0; r--) {
            for (int c = 0; c < n; c++) colBest[c] = max(colBest[c], (long long)board[r][c]);
            suffixTop[r] = top3FromColBest(colBest, n);
        }

        long long answer = NEG;
        for (int r2 = 1; r2 <= m - 2; r2++) {
            auto& cands1 = prefixTop[r2 - 1];
            auto& cands3 = suffixTop[r2 + 1];

            for (int c2 = 0; c2 < n; c2++) {
                long long v2 = board[r2][c2];

                for (auto& a : cands1) {
                    if (a.second == c2) continue;
                    for (auto& b : cands3) {
                        if (b.second == c2 || b.second == a.second) continue;
                        answer = max(answer, v2 + a.first + b.first);
                        break;
                    }
                }
            }
        }

        return answer;
    }
};
