// @leetcode id=2963 questionId=3212 slug=count-the-number-of-good-partitions lang=cpp site=leetcode.com title="Count the Number of Good Partitions"
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // For each value, record the last occurrence index
        unordered_map<int, int> lastOccurrence;
        for (int i = 0; i < n; i++) {
            lastOccurrence[nums[i]] = i;
        }
        
        // Count the number of "mandatory" segments
        // A segment boundary can be placed between i and i+1 only if
        // no number that starts at or before i has its last occurrence after i
        int segments = 1;
        int maxEnd = lastOccurrence[nums[0]];
        
        for (int i = 0; i < n - 1; i++) {
            maxEnd = max(maxEnd, lastOccurrence[nums[i]]);
            if (maxEnd <= i) {
                // We can place a boundary here, this creates a new segment
                segments++;
            }
        }
        
        // Answer is 2^(segments - 1) mod MOD
        long long ans = 1;
        long long base = 2;
        int exp = segments - 1;
        while (exp > 0) {
            if (exp & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        
        return (int)ans;
    }
};
