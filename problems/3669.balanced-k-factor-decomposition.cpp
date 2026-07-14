// @leetcode id=3669 questionId=3947 slug=balanced-k-factor-decomposition lang=cpp site=leetcode.com title="Balanced K-Factor Decomposition"
class Solution {
public:
    vector<int> divisorsOf(int x) {
        vector<int> result;
        for (int d = 1; (long long)d * d <= x; d++) {
            if (x % d == 0) {
                result.push_back(d);
                if (d != x / d) result.push_back(x / d);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }

    vector<int> best;
    int bestDiff;

    void dfs(int remaining, int minStart, int kLeft, vector<int>& current) {
        if (kLeft == 0) {
            if (remaining != 1) return;
            int diff = current.back() - current.front();
            if (diff < bestDiff) { bestDiff = diff; best = current; }
            return;
        }
        for (int d : divisorsOf(remaining)) {
            if (d < minStart) continue;
            current.push_back(d);
            dfs(remaining / d, d, kLeft - 1, current);
            current.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        bestDiff = INT_MAX;
        vector<int> current;
        dfs(n, 1, k, current);
        return best;
    }
};
