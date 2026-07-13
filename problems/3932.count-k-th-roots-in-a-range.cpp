// @leetcode id=3932 questionId=4303 slug=count-k-th-roots-in-a-range lang=cpp site=leetcode.com title="Count K-th Roots in a Range"
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if (k == 1) return r - l + 1; // x itself grows too slowly to bound the loop below

        int count = 0;
        for (long long x = 0; ; x++) {
            long long val = 1;
            bool overflow = false;
            for (int e = 0; e < k; e++) {
                val *= x;
                if (val > r) { overflow = true; break; }
            }
            if (overflow) break;
            if (val >= l && val <= r) count++;
        }
        return count;
    }
};
