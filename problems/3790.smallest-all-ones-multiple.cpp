// @leetcode id=3790 questionId=4175 slug=smallest-all-ones-multiple lang=cpp site=leetcode.com title="Smallest All-Ones Multiple"
class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int r = 0;
        for (int len = 1; len <= k; ++len) {
            r = (r * 10 + 1) % k;
            if (r == 0) return len;
        }
        return -1;
    }
};
