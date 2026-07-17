// @leetcode id=3939 questionId=3977 slug=count-non-adjacent-subsets-in-a-rooted-tree lang=cpp site=leetcode.com title="Count Non Adjacent Subsets in a Rooted Tree"
class Solution {
public:
    static const long long MOD = 1e9 + 7;

    vector<long long> convolve(vector<long long>& a, vector<long long>& b, int k) {
        vector<long long> res(k, 0);
        for (int p = 0; p < k; p++) {
            if (a[p] == 0) continue;
            for (int q = 0; q < k; q++) {
                if (b[q] == 0) continue;
                int r = (p + q) % k;
                res[r] = (res[r] + a[p] * b[q]) % MOD;
            }
        }
        return res;
    }

    vector<long long> shift(vector<long long>& a, int s, int k) {
        vector<long long> res(k, 0);
        for (int i = 0; i < k; i++) {
            res[(i + s) % k] = a[i];
        }
        return res;
    }

    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();

        vector<vector<long long>> accCombined(n, vector<long long>(k, 0));
        vector<vector<long long>> accNotIncluded(n, vector<long long>(k, 0));
        for (int i = 0; i < n; i++) {
            accCombined[i][0] = 1;
            accNotIncluded[i][0] = 1;
        }

        vector<vector<long long>> notIncluded(n, vector<long long>(k, 0));
        vector<vector<long long>> included(n, vector<long long>(k, 0));

        for (int i = n - 1; i >= 0; i--) {
            notIncluded[i] = accCombined[i];
            included[i] = shift(accNotIncluded[i], nums[i] % k, k);

            if (i != 0) {
                int p = parent[i];
                vector<long long> combinedThis(k, 0);
                for (int r = 0; r < k; r++) {
                    combinedThis[r] = (notIncluded[i][r] + included[i][r]) % MOD;
                }
                accCombined[p] = convolve(accCombined[p], combinedThis, k);
                accNotIncluded[p] = convolve(accNotIncluded[p], notIncluded[i], k);
            }
        }

        long long total = (notIncluded[0][0] + included[0][0]) % MOD;
        total = (total - 1 + MOD) % MOD;
        return (int)total;
    }
};
