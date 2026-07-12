// @leetcode id=440 questionId=440 slug=k-th-smallest-in-lexicographical-order lang=cpp site=leetcode.com title="K-th Smallest in Lexicographical Order"
class Solution {
public:
    int findKthNumber(int n, int k) {
        // Count how many numbers in [1,n] lie in the "prefix subtree" rooted
        // at `prefix` (i.e. start with that prefix), using its lexicographic
        // range [prefix, prefix+1) at each digit depth.
        auto countStep = [&](long long prefix) {
            long long cur = prefix, next = prefix + 1;
            long long count = 0;
            while (cur <= n) {
                count += min((long long)n + 1, next) - cur;
                cur *= 10;
                next *= 10;
            }
            return count;
        };

        long long cur = 1;
        k--; // account for cur itself as the 1st visited node
        while (k > 0) {
            long long steps = countStep(cur);
            if (steps <= k) {
                k -= steps;
                cur++; // move to sibling
            } else {
                cur *= 10; // descend into children
                k--;
            }
        }
        return (int)cur;
    }
};
