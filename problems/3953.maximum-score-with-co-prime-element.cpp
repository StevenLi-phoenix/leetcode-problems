// @leetcode id=3953 questionId=4182 slug=maximum-score-with-co-prime-element lang=cpp site=leetcode.com title="Maximum Score with Co-Prime Element"
class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        int n = nums.size();
        int M = maxVal;
        for (int v : nums) M = max(M, v);

        vector<int> freq(M + 1, 0);
        for (int v : nums) freq[v]++;

        vector<long long> cnt(M + 1, 0);
        for (int d = 1; d <= M; d++) {
            long long sum = 0;
            for (int k = d; k <= M; k += d) sum += freq[k];
            cnt[d] = sum;
        }

        vector<int> mobius(M + 1, 0);
        vector<int> primes;
        vector<bool> isComposite(M + 1, false);
        mobius[1] = 1;
        for (int i = 2; i <= M; i++) {
            if (!isComposite[i]) {
                primes.push_back(i);
                mobius[i] = -1;
            }
            for (int p : primes) {
                if ((long long)i * p > M) break;
                isComposite[i * p] = true;
                if (i % p == 0) {
                    mobius[i * p] = 0;
                    break;
                } else {
                    mobius[i * p] = -mobius[i];
                }
            }
        }

        vector<long long> coprimeCount(M + 1, 0);
        for (int d = 1; d <= M; d++) {
            if (mobius[d] == 0) continue;
            long long contribution = (long long)mobius[d] * cnt[d];
            for (int v = d; v <= M; v += d) {
                coprimeCount[v] += contribution;
            }
        }

        long long best = LLONG_MIN;

        for (int v = 1; v <= maxVal; v++) {
            long long notCoprime = n - coprimeCount[v];
            long long cost;
            if (freq[v] > 0) {
                cost = notCoprime - (v > 1 ? 1 : 0);
            } else {
                cost = max(notCoprime, 1LL);
            }
            best = max(best, (long long)v - cost);
        }

        for (int v = maxVal + 1; v <= M; v++) {
            if (freq[v] == 0) continue;
            long long notCoprime = n - coprimeCount[v];
            long long cost = notCoprime - 1;
            best = max(best, (long long)v - cost);
        }

        return (int)best;
    }
};
