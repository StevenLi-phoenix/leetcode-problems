// @leetcode id=1632 questionId=1257 slug=rank-transform-of-a-matrix lang=cpp site=leetcode.com title="Rank Transform of a Matrix"
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        // Process cells in increasing value order, grouped by equal value.
        // Within a group, union cells sharing a row or column (they must
        // end up with the same rank); each component's rank is one more
        // than the max row/col rank it touches, computed before any
        // updates from this group are applied (so ties don't interact).
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, pair<int, int>>> cells;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                cells.push_back({matrix[r][c], {r, c}});
        sort(cells.begin(), cells.end());

        vector<int> parent(m + n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        vector<int> rowRank(m, 0), colRank(n, 0);
        vector<vector<int>> answer(m, vector<int>(n, 0));

        int i = 0;
        int total = cells.size();
        while (i < total) {
            int j = i;
            while (j < total && cells[j].first == cells[i].first) j++;

            vector<int> touched;
            for (int t = i; t < j; t++) {
                int r = cells[t].second.first, c = cells[t].second.second;
                parent[r] = r;
                parent[m + c] = m + c;
                touched.push_back(r);
                touched.push_back(m + c);
            }
            for (int t = i; t < j; t++) {
                int r = cells[t].second.first, c = cells[t].second.second;
                int ru = find(r), cu = find(m + c);
                if (ru != cu) parent[ru] = cu;
            }

            unordered_map<int, int> maxRankByRoot;
            for (int t = i; t < j; t++) {
                int r = cells[t].second.first, c = cells[t].second.second;
                int root = find(r);
                int candidate = max(rowRank[r], colRank[c]) + 1;
                maxRankByRoot[root] = max(maxRankByRoot[root], candidate);
            }

            for (int t = i; t < j; t++) {
                int r = cells[t].second.first, c = cells[t].second.second;
                int root = find(r);
                int rank = maxRankByRoot[root];
                answer[r][c] = rank;
                rowRank[r] = rank;
                colRank[c] = rank;
            }

            i = j;
        }

        return answer;
    }
};
