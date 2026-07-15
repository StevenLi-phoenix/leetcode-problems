// @leetcode id=1711 questionId=1830 slug=count-good-meals lang=cpp site=leetcode.com title="Count Good Meals"
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long count = 0;

        for (int d : deliciousness) {
            for (int p = 0; p <= 21; p++) {
                int target = (1 << p) - d;
                if (target < 0) continue;
                auto it = freq.find(target);
                if (it != freq.end()) count = (count + it->second) % MOD;
            }
            freq[d]++;
        }
        return (int)count;
    }
};
