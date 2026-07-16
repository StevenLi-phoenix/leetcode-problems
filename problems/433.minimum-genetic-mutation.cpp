// @leetcode id=433 questionId=433 slug=minimum-genetic-mutation lang=cpp site=leetcode.com title="Minimum Genetic Mutation"
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        auto diff = [](const string& a, const string& b) {
            int d = 0;
            for (int i = 0; i < 8; i++) if (a[i] != b[i]) d++;
            return d;
        };

        int n = bank.size();
        vector<bool> visited(n, false);
        queue<pair<string, int>> bfs;
        bfs.push({startGene, 0});

        while (!bfs.empty()) {
            auto [gene, steps] = bfs.front(); bfs.pop();
            if (gene == endGene) return steps;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && diff(gene, bank[i]) == 1) {
                    visited[i] = true;
                    bfs.push({bank[i], steps + 1});
                }
            }
        }
        return -1;
    }
};
