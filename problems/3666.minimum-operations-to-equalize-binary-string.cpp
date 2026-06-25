// @leetcode id=3666 questionId=3983 slug=minimum-operations-to-equalize-binary-string lang=cpp site=leetcode.com title="Minimum Operations to Equalize Binary String"
class Solution {
public:
int minOperations(string s, int k) {
int n = s.size();
int c = count(s.begin(), s.end(), '0');
if (c == 0) return 0;
if (k == n) {
return (c == n) ? 1 : -1;
}
// k < n
// k even, c odd -> impossible (t*k always even)
if (k % 2 == 0 && c % 2 == 1) return -1;

// Find min t such that:
// 1. t*k >= c
// 2. t*k % 2 == c % 2
// 3. We can assign flip counts f_i (odd for zeros, even for ones)
//    with sum = t*k and max(f_i) <= t

// For zeros: f_i is odd >= 1, for ones: f_i is even >= 0
// Min sum = c (each zero = 1, each one = 0)
// Max sum with constraint max <= t:
//   zeros can be at most t if t is odd, or t-1 if t is even
//   ones can be at most t if t is even, or t-1 if t is odd
// Max sum = c * max_odd + (n-c) * max_even
//   where max_odd = t if t odd, t-1 if t even
//   max_even = t if t even, t-1 if t odd

// We need: min_sum <= t*k <= max_sum and parity match
for (int t = 1; t <= 2 * n; t++) {
long long total = (long long)t * k;
if (total < c) continue;
if (total % 2 != c % 2) continue;
// Check max constraint
int max_odd = (t % 2 == 1) ? t : t - 1; // max odd <= t
int max_even = (t % 2 == 0) ? t : t - 1; // max even <= t
long long max_sum = (long long)c * max_odd + (long long)(n - c) * max_even;
if (total <= max_sum) return t;
}
return -1;
}
};
