// @leetcode id=3133 questionId=3394 slug=minimum-array-end lang=cpp site=leetcode.com title="Minimum Array End"
class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long m = (long long)(n - 1);
        int bit = 0; // current bit of m to place
        
        for (int i = 0; i < 64 && bit < 32; i++) {
            // If bit i is NOT set in x, we fill it from m
            if (!((result >> i) & 1)) {
                if ((m >> bit) & 1) {
                    result |= (1LL << i);
                }
                bit++;
            }
        }
        return result;
    }
};
