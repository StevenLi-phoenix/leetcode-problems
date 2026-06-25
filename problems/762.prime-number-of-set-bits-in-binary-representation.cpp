// @leetcode id=762 questionId=767 slug=prime-number-of-set-bits-in-binary-representation lang=cpp site=leetcode.com title="Prime Number of Set Bits in Binary Representation"
class Solution {
public:
int countPrimeSetBits(int left, int right) {
// Max bits for numbers up to 10^6 is about 20
// Primes up to 20: 2, 3, 5, 7, 11, 13, 17, 19
unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
int count = 0;
for (int i = left; i <= right; i++) {
if (primes.count(__builtin_popcount(i))) count++;
}
return count;
}
};
