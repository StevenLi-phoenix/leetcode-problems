// @leetcode id=3448 questionId=3696 slug=count-substrings-divisible-by-last-digit lang=cpp site=leetcode.com title="Count Substrings Divisible By Last Digit"
class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long total = 0;

        for (int d = 1; d <= 9; d++) {
            vector<long long> bucket(d, 0);
            for (int j = 0; j < n; j++) {
                int digit = s[j] - '0';
                vector<long long> newBucket(d, 0);
                for (int r = 0; r < d; r++) {
                    if (bucket[r] == 0) continue;
                    int newR = (r * 10 + digit) % d;
                    newBucket[newR] += bucket[r];
                }
                newBucket[digit % d] += 1;
                bucket = newBucket;

                if (digit == d) {
                    total += bucket[0];
                }
            }
        }

        return total;
    }
};
