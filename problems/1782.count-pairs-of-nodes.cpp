// @leetcode id=1782 questionId=1891 slug=count-pairs-of-nodes lang=cpp site=leetcode.com title="Count Pairs Of Nodes"
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> deg(n + 1, 0);
        map<pair<int, int>, int> edgeCount;

        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (a > b) swap(a, b);
            deg[a]++;
            deg[b]++;
            edgeCount[{a, b}]++;
        }

        vector<int> sortedDeg(deg.begin() + 1, deg.end());
        sort(sortedDeg.begin(), sortedDeg.end());

        int m = queries.size();
        vector<int> answers(m);

        for (int qi = 0; qi < m; qi++) {
            int q = queries[qi];
            long long count = 0;
            int left = 0, right = n - 1;
            while (left < right) {
                if (sortedDeg[left] + sortedDeg[right] > q) {
                    count += right - left;
                    right--;
                } else {
                    left++;
                }
            }

            for (auto& p : edgeCount) {
                int a = p.first.first, b = p.first.second;
                int c = p.second;
                int sum = deg[a] + deg[b];
                if (sum > q && sum - c <= q) count--;
            }

            answers[qi] = (int)count;
        }

        return answers;
    }
};
