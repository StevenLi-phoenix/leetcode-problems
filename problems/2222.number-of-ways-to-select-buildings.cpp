// @leetcode id=2222 questionId=2325 slug=number-of-ways-to-select-buildings lang=cpp site=leetcode.com title="Number of Ways to Select Buildings"
class Solution {
public:
    long long numberOfWays(string s) {
        long long c0 = 0, c1 = 0;   // count of 0s and 1s seen
        long long c01 = 0, c10 = 0; // "01" and "10" pairs seen
        long long ans = 0;
        
        for (char c : s) {
            if (c == '0') {
                // Complete "010": extend each "01" pair with this '0'
                ans += c01;
                // New "10" pair: pair this '0' with each '1' seen before
                c10 += c1;
                c0++;
            } else { // '1'
                // Complete "101": extend each "10" pair with this '1'
                ans += c10;
                // New "01" pair: pair this '1' with each '0' seen before
                c01 += c0;
                c1++;
            }
        }
        
        return ans;
    }
};
