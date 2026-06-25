// @leetcode id=263 questionId=263 slug=ugly-number lang=cpp site=leetcode.com title="Ugly Number"
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (int p : {2, 3, 5}) {
            while (n % p == 0) n /= p;
        }
        return n == 1;
    }
};
