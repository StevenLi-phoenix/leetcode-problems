// @leetcode id=3334 questionId=3593 slug=find-the-maximum-factor-score-of-array lang=cpp site=leetcode.com title="Find the Maximum Factor Score of Array"
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefGcd(n), prefLcm(n);
        vector<long long> sufGcd(n), sufLcm(n);

        prefGcd[0] = nums[0];
        prefLcm[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefGcd[i] = gcd(prefGcd[i - 1], (long long)nums[i]);
            prefLcm[i] = lcm(prefLcm[i - 1], (long long)nums[i]);
        }
        sufGcd[n - 1] = nums[n - 1];
        sufLcm[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sufGcd[i] = gcd(sufGcd[i + 1], (long long)nums[i]);
            sufLcm[i] = lcm(sufLcm[i + 1], (long long)nums[i]);
        }

        long long best = prefGcd[n - 1] * prefLcm[n - 1];
        if (n == 1) return best;
        for (int i = 0; i < n; i++) {
            long long g, l;
            if (i == 0) { g = sufGcd[1]; l = sufLcm[1]; }
            else if (i == n - 1) { g = prefGcd[n - 2]; l = prefLcm[n - 2]; }
            else {
                g = gcd(prefGcd[i - 1], sufGcd[i + 1]);
                l = lcm(prefLcm[i - 1], sufLcm[i + 1]);
            }
            best = max(best, g * l);
        }
        return best;
    }

private:
    long long gcd(long long a, long long b) {
        while (b) { a %= b; swap(a, b); }
        return a;
    }
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};
