// @leetcode id=3671 questionId=3989 slug=sum-of-beautiful-subsequences lang=cpp site=leetcode.com title="Sum of Beautiful Subsequences"
class Solution {
public:
    static const long long MOD = 1000000007;

    int totalBeauty(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<vector<int>> lists(maxVal + 1);
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            for (int d = 1; (long long)d * d <= v; d++) {
                if (v % d == 0) {
                    lists[d].push_back(v);
                    int other = v / d;
                    if (other != d) lists[other].push_back(v);
                }
            }
        }

        vector<long long> bit(maxVal + 2, 0);
        auto update = [&](int pos, long long val, int size) {
            for (; pos <= size; pos += pos & (-pos)) bit[pos] = (bit[pos] + val) % MOD;
        };
        auto query = [&](int pos) {
            long long res = 0;
            for (; pos > 0; pos -= pos & (-pos)) res = (res + bit[pos]) % MOD;
            return res;
        };

        vector<long long> A(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            if (lists[g].empty()) continue;
            int sizeG = maxVal / g;
            long long total = 0;
            for (int val : lists[g]) {
                int p = val / g;
                long long dp = (1 + query(p - 1)) % MOD;
                update(p, dp, sizeG);
                total = (total + dp) % MOD;
            }
            A[g] = total;
            fill(bit.begin(), bit.begin() + sizeG + 2, 0);
        }

        vector<long long> exact(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; g--) {
            long long e = A[g];
            for (int m = 2 * g; m <= maxVal; m += g) {
                e = (e - exact[m] + MOD) % MOD;
            }
            exact[g] = e;
        }

        long long answer = 0;
        for (int g = 1; g <= maxVal; g++) {
            answer = (answer + (long long)g % MOD * exact[g]) % MOD;
        }

        return (int)answer;
    }
};
