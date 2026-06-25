# @leetcode id=1492 questionId=1585 slug=the-kth-factor-of-n lang=python3 site=leetcode.com title="The kth Factor of n"
class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        factors = []
        for i in range(1, n + 1):
            if n % i == 0:
                factors.append(i)
            if len(factors) >= k:
                break
        return factors[k - 1] if len(factors) >= k else -1
