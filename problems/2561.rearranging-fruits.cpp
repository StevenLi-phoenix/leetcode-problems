// @leetcode id=2561 questionId=2689 slug=rearranging-fruits lang=cpp site=leetcode.com title="Rearranging Fruits"
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> cnt;
        int minOverall = INT_MAX;

        for (int x : basket1) { cnt[x]++; minOverall = min(minOverall, x); }
        for (int x : basket2) { cnt[x]--; minOverall = min(minOverall, x); }

        vector<int> diffs;
        for (auto& [v, c] : cnt) {
            if (c % 2 != 0) return -1;
            int half = abs(c) / 2;
            for (int i = 0; i < half; i++) diffs.push_back(v);
        }

        sort(diffs.begin(), diffs.end());
        int m = diffs.size();

        long long cost = 0;
        for (int i = 0; i < m / 2; i++) {
            cost += min((long long)diffs[i], 2LL * minOverall);
        }

        return cost;
    }
};
