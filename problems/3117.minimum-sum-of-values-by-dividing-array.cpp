// @leetcode id=3117 questionId=3364 slug=minimum-sum-of-values-by-dividing-array lang=cpp site=leetcode.com title="Minimum Sum of Values by Dividing Array"
class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        const long long INF = LLONG_MAX / 2;

        vector<long long> dpPrev(n + 1, INF);
        dpPrev[0] = 0;

        for (int j = 1; j <= m; j++) {
            vector<long long> dpCurr(n + 1, INF);
            vector<pair<int,long long>> stateList; // (andVal, cost)

            for (int i = 1; i <= n; i++) {
                vector<pair<int,long long>> newState;
                for (auto& [andVal, cost] : stateList) {
                    int nv = andVal & nums[i - 1];
                    bool merged = false;
                    for (auto& p : newState) {
                        if (p.first == nv) { p.second = min(p.second, cost); merged = true; break; }
                    }
                    if (!merged) newState.push_back({nv, cost});
                }
                if (dpPrev[i - 1] < INF) {
                    int nv = nums[i - 1];
                    bool merged = false;
                    for (auto& p : newState) {
                        if (p.first == nv) { p.second = min(p.second, dpPrev[i - 1]); merged = true; break; }
                    }
                    if (!merged) newState.push_back({nv, dpPrev[i - 1]});
                }
                stateList = newState;

                for (auto& [andVal, cost] : stateList) {
                    if (andVal == andValues[j - 1]) {
                        dpCurr[i] = min(dpCurr[i], cost + nums[i - 1]);
                    }
                }
            }

            dpPrev = dpCurr;
        }

        return dpPrev[n] >= INF ? -1 : (int)dpPrev[n];
    }
};
