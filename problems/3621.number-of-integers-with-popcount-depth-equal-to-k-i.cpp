// @leetcode id=3621 questionId=3937 slug=number-of-integers-with-popcount-depth-equal-to-k-i lang=cpp site=leetcode.com title="Number of Integers With Popcount-Depth Equal to K I"
class Solution {
public:
    long long popcountDepth(long long n, int k) {
        auto getDepth = [](int x) -> int {
            if (x == 1) return 0;
            int depth = 0;
            while (x != 1) {
                x = __builtin_popcount(x);
                depth++;
            }
            return depth;
        };

        vector<int> depth(65);
        for (int i = 1; i <= 64; i++) {
            depth[i] = getDepth(i);
        }

        long long ans = 0;
        if (k == 0 && n >= 1) ans++;

        if (n < 2) return ans;

        string binary = "";
        long long temp = n;
        while (temp > 0) {
            binary = (char)('0' + (temp & 1)) + binary;
            temp >>= 1;
        }

        int bits = binary.size();
        map<tuple<int, int, bool>, long long> memo;

        function<long long(int, int, bool)> dp = [&](int pos, int popcount, bool tight) -> long long {
            if (pos == bits) {
                if (popcount == 0) return 0;
                int numDepth = 1 + depth[popcount];
                return numDepth == k ? 1 : 0;
            }

            auto key = make_tuple(pos, popcount, tight);
            if (memo.count(key)) return memo[key];

            int limit = tight ? (binary[pos] - '0') : 1;
            long long result = 0;

            for (int digit = 0; digit <= limit; digit++) {
                result += dp(pos + 1, popcount + digit, tight && (digit == limit));
            }

            return memo[key] = result;
        };

        long long dpResult = dp(0, 0, true);
        if (k == 1) dpResult--;
        return ans + dpResult;
    }
};
