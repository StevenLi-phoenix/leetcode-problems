// @leetcode id=3413 questionId=3715 slug=maximum-coins-from-k-consecutive-bags lang=cpp site=leetcode.com title="Maximum Coins From K Consecutive Bags"
class Solution {
public:
    vector<long long> L, R, C, prefixLen, prefixVal;

    long long calcUpTo(long long x) {
        if (x < 0) return 0;
        int n = L.size();
        int pos = upper_bound(R.begin(), R.end(), x) - R.begin();
        long long val = prefixVal[pos];
        if (pos < n && L[pos] <= x) {
            val += C[pos] * (x - L[pos] + 1);
        }
        return val;
    }

    long long windowSum(long long s, long long k) {
        return calcUpTo(s + k - 1) - calcUpTo(s - 1);
    }

    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int n = coins.size();
        L.resize(n); R.resize(n); C.resize(n);
        for (int i = 0; i < n; i++) {
            L[i] = coins[i][0];
            R[i] = coins[i][1];
            C[i] = coins[i][2];
        }
        prefixLen.assign(n + 1, 0);
        prefixVal.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            long long len = R[i] - L[i] + 1;
            prefixLen[i + 1] = prefixLen[i] + len;
            prefixVal[i + 1] = prefixVal[i] + C[i] * len;
        }

        long long best = 0;
        for (int i = 0; i < n; i++) {
            best = max(best, windowSum(L[i], k));
            best = max(best, windowSum(R[i] - k + 1, k));
        }
        return best;
    }
};
