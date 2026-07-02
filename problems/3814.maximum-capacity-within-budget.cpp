// @leetcode id=3814 questionId=4079 slug=maximum-capacity-within-budget lang=cpp site=leetcode.com title="Maximum Capacity Within Budget"
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) idx[i] = i;
        stable_sort(idx.begin(), idx.end(), [&](int a, int b) {
            return costs[a] < costs[b];
        });

        vector<int> costSorted(n), capSorted(n);
        for (int i = 0; i < n; ++i) {
            costSorted[i] = costs[idx[i]];
            capSorted[i] = capacity[idx[i]];
        }

        const long long NEG = LLONG_MIN / 2;
        vector<long long> max1(n + 1, NEG), max2(n + 1, NEG);
        vector<int> max1Idx(n + 1, -1);
        for (int k = 1; k <= n; ++k) {
            long long val = capSorted[k - 1];
            int at = k - 1;
            if (val > max1[k - 1]) {
                max2[k] = max1[k - 1];
                max1[k] = val;
                max1Idx[k] = at;
            } else {
                max1[k] = max1[k - 1];
                max1Idx[k] = max1Idx[k - 1];
                max2[k] = max(max2[k - 1], val);
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (costSorted[i] < budget) ans = max(ans, (long long)capSorted[i]);
        }

        for (int j = 0; j < n; ++j) {
            long long threshold = (long long)budget - costSorted[j];
            int r = (int)(lower_bound(costSorted.begin(), costSorted.end(), threshold) - costSorted.begin());
            if (r <= 0) continue;
            long long candidate;
            if (max1Idx[r] == j) candidate = max2[r];
            else candidate = max1[r];
            if (candidate <= NEG / 2) continue;
            ans = max(ans, candidate + (long long)capSorted[j]);
        }

        return (int)ans;
    }
};
