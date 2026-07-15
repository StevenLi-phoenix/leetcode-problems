// @leetcode id=3765 questionId=4100 slug=complete-prime-number lang=cpp site=leetcode.com title="Complete Prime Number"
class Solution {
public:
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            long long prefix = stoll(s.substr(0, len));
            long long suffix = stoll(s.substr(n - len, len));
            if (!isPrime(prefix) || !isPrime(suffix)) return false;
        }
        return true;
    }

private:
    bool isPrime(long long x) {
        if (x < 2) return false;
        for (long long i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
};
