// @leetcode id=477 questionId=477 slug=total-hamming-distance lang=cpp site=leetcode.com title="Total Hamming Distance"
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int ones = 0;
            for (int x : nums) {
                if (x & (1 << bit)) ++ones;
            }
            total += (long long)ones * (n - ones);
        }
        return (int)total;
    }
};
