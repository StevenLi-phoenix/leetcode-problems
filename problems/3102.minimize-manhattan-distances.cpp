// @leetcode id=3102 questionId=3344 slug=minimize-manhattan-distances lang=cpp site=leetcode.com title="Minimize Manhattan Distances"
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<long long> u(n), v(n);
        for (int i = 0; i < n; i++) {
            u[i] = points[i][0] + points[i][1];
            v[i] = points[i][0] - points[i][1];
        }

        multiset<long long> Uset(u.begin(), u.end());
        multiset<long long> Vset(v.begin(), v.end());

        auto maxU = [&]() { return *Uset.rbegin(); };
        auto minU = [&]() { return *Uset.begin(); };
        auto maxV = [&]() { return *Vset.rbegin(); };
        auto minV = [&]() { return *Vset.begin(); };

        set<int> candidates;
        long long mu = maxU(), nu = minU(), mv = maxV(), nv = minV();
        for (int i = 0; i < n; i++) {
            if (u[i] == mu || u[i] == nu || v[i] == mv || v[i] == nv) candidates.insert(i);
        }

        long long best = LLONG_MAX;
        for (int idx : candidates) {
            Uset.erase(Uset.find(u[idx]));
            Vset.erase(Vset.find(v[idx]));

            long long diffU = *Uset.rbegin() - *Uset.begin();
            long long diffV = *Vset.rbegin() - *Vset.begin();
            long long cur = max(diffU, diffV);
            best = min(best, cur);

            Uset.insert(u[idx]);
            Vset.insert(v[idx]);
        }

        return (int)best;
    }
};
