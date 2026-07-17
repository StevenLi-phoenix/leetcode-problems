// @leetcode id=3518 questionId=3813 slug=smallest-palindromic-rearrangement-ii lang=cpp site=leetcode.com title="Smallest Palindromic Rearrangement II"
class Solution {
public:
    static const long long LIMIT = 2000000LL;

    long long binomCapped(long long n, long long r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long result = 1;
        for (long long i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;
            if (result > LIMIT) return LIMIT + 1;
        }
        return result;
    }

    long long permCountCapped(array<int, 26>& counts, int remaining) {
        long long result = 1;
        int used = 0;
        for (int c = 0; c < 26; c++) {
            int cnt = counts[c];
            if (cnt == 0) continue;
            if (result <= LIMIT) {
                long long comb = binomCapped(used + cnt, cnt);
                if (comb > LIMIT || result > LIMIT) result = LIMIT + 1;
                else {
                    result *= comb;
                    if (result > LIMIT) result = LIMIT + 1;
                }
            }
            used += cnt;
        }
        return result;
    }

    string smallestPalindrome(string s, int kInput) {
        long long k = kInput;
        array<int, 26> full{};
        for (char ch : s) full[ch - 'a']++;

        array<int, 26> halfCount{};
        int oddChar = -1;
        for (int c = 0; c < 26; c++) {
            halfCount[c] = full[c] / 2;
            if (full[c] % 2 == 1) oddChar = c;
        }

        int halfLen = 0;
        for (int c = 0; c < 26; c++) halfLen += halfCount[c];

        long long total = permCountCapped(halfCount, halfLen);
        if (total < k) return "";

        array<int, 26> counts = halfCount;
        int remaining = halfLen;
        string half;
        half.reserve(halfLen);

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (counts[c] == 0) continue;
                counts[c]--;
                remaining--;
                long long cnt = permCountCapped(counts, remaining);
                if (cnt >= k) {
                    half.push_back('a' + c);
                    break;
                } else {
                    k -= cnt;
                    counts[c]++;
                    remaining++;
                }
            }
        }

        string result = half;
        if (oddChar != -1) result.push_back('a' + oddChar);
        for (int i = half.size() - 1; i >= 0; i--) result.push_back(half[i]);

        return result;
    }
};
