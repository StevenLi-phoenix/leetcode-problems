// @leetcode id=2025 questionId=2135 slug=maximum-number-of-ways-to-partition-an-array lang=cpp site=leetcode.com title="Maximum Number of Ways to Partition an Array"
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        long long total = prefix[n];

        unordered_map<long long, int> prefixCount, suffixCount;
        for (int p = 1; p <= n - 1; p++) suffixCount[prefix[p]]++;

        int baseline = 0;
        if (total % 2 == 0) {
            auto it = suffixCount.find(total / 2);
            if (it != suffixCount.end()) baseline = it->second;
        }

        int best = baseline;
        for (int i = 0; i < n; i++) {
            long long diff = k - nums[i];
            int candidate = 0;
            if ((total - diff) % 2 == 0) {
                long long target1 = (total - diff) / 2;
                auto it = suffixCount.find(target1);
                if (it != suffixCount.end()) candidate += it->second;
            }
            if ((total + diff) % 2 == 0) {
                long long target2 = (total + diff) / 2;
                auto it = prefixCount.find(target2);
                if (it != prefixCount.end()) candidate += it->second;
            }
            best = max(best, candidate);

            if (i + 1 <= n - 1) {
                prefixCount[prefix[i + 1]]++;
                suffixCount[prefix[i + 1]]--;
            }
        }
        return best;
    }
};
