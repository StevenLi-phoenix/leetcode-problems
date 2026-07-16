// @leetcode id=3811 questionId=4143 slug=number-of-alternating-xor-partitions lang=cpp site=leetcode.com title="Number of Alternating XOR Partitions"
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] ^ nums[i - 1];

        unordered_map<int, long long> mapT1, mapT2;
        mapT1[0] = 1;

        long long finalT1 = 0, finalT2 = 0;
        for (int j = 1; j <= n; j++) {
            long long newT1 = 0, newT2 = 0;
            auto it2 = mapT2.find(prefix[j] ^ target2);
            if (it2 != mapT2.end()) newT1 = it2->second;
            auto it1 = mapT1.find(prefix[j] ^ target1);
            if (it1 != mapT1.end()) newT2 = it1->second;

            mapT1[prefix[j]] = (mapT1[prefix[j]] + newT1) % MOD;
            mapT2[prefix[j]] = (mapT2[prefix[j]] + newT2) % MOD;

            if (j == n) { finalT1 = newT1; finalT2 = newT2; }
        }
        return (int)((finalT1 + finalT2) % MOD);
    }
};
