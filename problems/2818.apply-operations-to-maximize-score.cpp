// @leetcode id=2818 questionId=3001 slug=apply-operations-to-maximize-score lang=cpp site=leetcode.com title="Apply Operations to Maximize Score"
class Solution {
public:
    int primeScore(int x) {
        int score = 0;
        for (int p = 2; (long long)p * p <= x; p++) {
            if (x % p == 0) {
                score++;
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) score++;
        return score;
    }

    long long power(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int maximumScore(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<int> ps(n);
        for (int i = 0; i < n; i++) ps[i] = primeScore(nums[i]);

        vector<int> left(n), right(n);
        vector<int> stack;

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && ps[stack.back()] < ps[i]) stack.pop_back();
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }
        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && ps[stack.back()] <= ps[i]) stack.pop_back();
            right[i] = stack.empty() ? n : stack.back();
            stack.push_back(i);
        }

        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] > nums[b]; });

        const long long MOD = 1e9 + 7;
        long long result = 1;
        for (int i : idx) {
            if (k <= 0) break;
            long long count = (long long)(i - left[i]) * (right[i] - i);
            long long use = min(count, k);
            result = (result * power(nums[i], use, MOD)) % MOD;
            k -= use;
        }
        return (int)result;
    }
};
