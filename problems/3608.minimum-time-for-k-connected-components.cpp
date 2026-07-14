// @leetcode id=3608 questionId=3908 slug=minimum-time-for-k-connected-components lang=cpp site=leetcode.com title="Minimum Time for K Connected Components"
class Solution {
public:
    vector<int> parent_;

    int find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

    int countComponents(int n, vector<vector<int>>& edges, int t) {
        parent_.resize(n);
        for (int i = 0; i < n; i++) parent_[i] = i;
        int components = n;
        for (auto& e : edges) {
            if (e[2] <= t) continue; // this edge is removed by time t
            int ru = find(e[0]), rv = find(e[1]);
            if (ru != rv) { parent_[ru] = rv; components--; }
        }
        return components;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<int> candidates = {0};
        for (auto& e : edges) candidates.push_back(e[2]);
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        int lo = 0, hi = candidates.size() - 1, ans = candidates.back();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (countComponents(n, edges, candidates[mid]) >= k) {
                ans = candidates[mid];
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
