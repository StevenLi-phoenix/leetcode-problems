// @leetcode id=3145 questionId=3411 slug=find-products-of-elements-of-big-array lang=cpp site=leetcode.com title="Find Products of Elements of Big Array"
class Solution {
public:
    static const int BITS = 55;

    long long countSetBit(long long X, int b) {
        if (X < 0) return 0;
        long long cycle = 1LL << (b + 1);
        long long half = 1LL << b;
        long long full = (X + 1) / cycle;
        long long rem = (X + 1) % cycle;
        return full * half + max(0LL, rem - half);
    }

    long long cumCount(long long X) {
        long long total = 0;
        for (int b = 0; b < BITS; b++) total += countSetBit(X, b);
        return total;
    }

    long long weightedSum(long long X) {
        long long total = 0;
        for (int b = 0; b < BITS; b++) total += countSetBit(X, b) * (long long)b;
        return total;
    }

    // exponentSum(n) = sum of bit-position exponents for the first n entries (n>=0) of big_nums
    long long exponentSum(long long n) {
        if (n <= 0) return 0;

        long long lo = 1, hi = 1LL << 51;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cumCount(mid) >= n) hi = mid;
            else lo = mid + 1;
        }
        long long i0 = lo;

        long long fullSum = weightedSum(i0 - 1);
        long long remaining = n - cumCount(i0 - 1);

        // take the smallest `remaining` set bits of i0
        for (int b = 0; b < BITS && remaining > 0; b++) {
            if (i0 & (1LL << b)) {
                fullSum += b;
                remaining--;
            }
        }

        return fullSum;
    }

    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1 % mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            long long from = q[0], to = q[1], mod = q[2];
            long long totalExp = exponentSum(to + 1) - exponentSum(from);
            answer.push_back((int)modpow(2, totalExp, mod));
        }

        return answer;
    }
};
