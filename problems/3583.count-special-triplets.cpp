// @leetcode id=3583 questionId=3885 slug=count-special-triplets lang=cpp site=leetcode.com title="Count Special Triplets"
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> suffixCount, leftCount;
        for (int x : nums) suffixCount[x]++;

        long long total = 0;
        for (int x : nums) {
            suffixCount[x]--;
            long long target = (long long)x * 2;
            if (target <= 100000) {
                auto itLeft = leftCount.find((int)target);
                auto itRight = suffixCount.find((int)target);
                long long l = (itLeft != leftCount.end()) ? itLeft->second : 0;
                long long r = (itRight != suffixCount.end()) ? itRight->second : 0;
                total = (total + (l * r) % MOD) % MOD;
            }
            leftCount[x]++;
        }
        return (int)total;
    }
};
