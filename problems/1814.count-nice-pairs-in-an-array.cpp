// @leetcode id=1814 questionId=1925 slug=count-nice-pairs-in-an-array lang=cpp site=leetcode.com title="Count Nice Pairs in an Array"
class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> freq;
        long long total = 0;
        for (int v : nums) {
            int diff = v - reverseNum(v);
            total = (total + freq[diff]) % MOD;
            freq[diff]++;
        }
        return (int)total;
    }
};
