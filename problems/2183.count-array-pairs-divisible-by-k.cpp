// @leetcode id=2183 questionId=2301 slug=count-array-pairs-divisible-by-k lang=cpp site=leetcode.com title="Count Array Pairs Divisible by K"
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        vector<long long> divisors;
        for (long long d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                divisors.push_back(d);
                if (d != k / d) divisors.push_back(k / d);
            }
        }

        unordered_map<long long, long long> count;
        for (int num : nums) {
            long long g = std::__gcd((long long)num, (long long)k);
            count[g]++;
        }

        long long total = 0;
        int m = divisors.size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                long long d1 = divisors[i], d2 = divisors[j];
                if ((d1 * d2) % k != 0) continue;
                if (!count.count(d1) || !count.count(d2)) continue;

                if (d1 == d2) {
                    long long c = count[d1];
                    total += c * (c - 1) / 2;
                } else {
                    total += count[d1] * count[d2];
                }
            }
        }

        return total;
    }
};
