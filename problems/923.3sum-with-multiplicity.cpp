// @leetcode id=923 questionId=959 slug=3sum-with-multiplicity lang=cpp site=leetcode.com title="3Sum With Multiplicity"
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long MOD = 1'000'000'007;
        long long cnt[101] = {};
        for (int x : arr) cnt[x]++;

        auto choose2 = [](long long n) { return n * (n - 1) / 2; };
        auto choose3 = [](long long n) { return n * (n - 1) * (n - 2) / 6; };

        long long total = 0;
        for (int a = 0; a <= 100; a++) {
            if (cnt[a] == 0) continue;
            for (int b = a; b <= 100; b++) {
                int c = target - a - b;
                if (c < b || c > 100 || cnt[b] == 0 || cnt[c] == 0) continue;
                if (a == b && b == c) total += choose3(cnt[a]);
                else if (a == b) total += choose2(cnt[a]) * cnt[c];
                else if (b == c) total += cnt[a] * choose2(cnt[b]);
                else total += cnt[a] * cnt[b] * cnt[c];
                total %= MOD;
            }
        }
        return (int)total;
    }
};
