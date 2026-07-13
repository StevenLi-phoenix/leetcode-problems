// @leetcode id=1362 questionId=1276 slug=closest-divisors lang=cpp site=leetcode.com title="Closest Divisors"
class Solution {
public:
    vector<int> closestDivisors(int num) {
        auto closestPair = [](long long n) -> vector<int> {
            for (long long a = (long long)sqrt((double)n); a >= 1; a--) {
                if (n % a == 0) return {(int)a, (int)(n / a)};
            }
            return {1, (int)n};
        };

        vector<int> p1 = closestPair(num + 1);
        vector<int> p2 = closestPair(num + 2);
        long long diff1 = abs((long long)p1[0] - p1[1]);
        long long diff2 = abs((long long)p2[0] - p2[1]);
        return diff1 <= diff2 ? p1 : p2;
    }
};
