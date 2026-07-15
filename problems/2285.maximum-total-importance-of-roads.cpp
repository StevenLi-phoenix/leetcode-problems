// @leetcode id=2285 questionId=2379 slug=maximum-total-importance-of-roads lang=cpp site=leetcode.com title="Maximum Total Importance of Roads"
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        for (auto& r : roads) {
            degree[r[0]]++;
            degree[r[1]]++;
        }

        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return degree[a] > degree[b]; });

        vector<long long> value(n);
        long long v = n;
        for (int i : idx) value[i] = v--;

        long long total = 0;
        for (auto& r : roads) total += value[r[0]] + value[r[1]];
        return total;
    }
};
