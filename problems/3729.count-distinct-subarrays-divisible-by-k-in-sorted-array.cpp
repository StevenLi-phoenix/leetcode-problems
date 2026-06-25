// @leetcode id=3729 questionId=4063 slug=count-distinct-subarrays-divisible-by-k-in-sorted-array lang=cpp site=leetcode.com title="Count Distinct Subarrays Divisible by K in Sorted Array"
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Build runs
        vector<pair<long long, long long>> runs; // (value, count)
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && nums[j] == nums[i]) j++;
            runs.push_back({nums[i], j - i});
            i = j;
        }
        int m = runs.size();
        
        // Prefix sums over runs (full elements)
        // S[i] = sum of elements in runs 0..i-1
        vector<long long> S(m + 1, 0);
        for (int i = 0; i < m; i++) {
            S[i + 1] = S[i] + runs[i].first * runs[i].second;
        }
        
        long long ans = 0;
        
        // 1. Count good single-value subarrays
        // For run i with value v and count c:
        // Count L in [1, c] with L*v % k == 0
        // L*v % k == 0 <=> L % (k/gcd(v,k)) == 0
        // Count = floor(c / (k/gcd(v,k))) = floor(c * gcd(v,k) / k)
        for (int i = 0; i < m; i++) {
            long long v = runs[i].first % k;
            long long c = runs[i].second;
            if (v == 0) {
                // Any length works
                ans += c;
            } else {
                long long g = __gcd(v, (long long)k);
                long long period = k / g; // smallest L with L*v % k == 0
                ans += c / period;
            }
        }
        
        // 2. Count good multi-value subarrays
        // For pair (i, j) with i < j: count (l1, l2) with l1 in [1, cnt[i]], l2 in [1, cnt[j]]
        // and (l1*val[i] - S[i+1] + S[j] + l2*val[j]) % k == 0
        // Rewrite: (l1*val[i] - S[i+1]) % k == -(S[j] + l2*val[j]) % k
        
        // Use hash map: key = (l1*val[i] - S[i+1]) % k, count = frequency
        unordered_map<long long, long long> freq;
        
        // Process runs left to right
        // Before processing run j, add all (i=0..j-1, l1) entries to freq
        // Then for each l2 in [1, cnt[j]], look up the target
        
        // Initialize: add all (l1, i=0) entries
        // We process incrementally: when we move to run j, we add all (l1, j-1) entries
        
        for (int j = 0; j < m; j++) {
            // Add run j-1's left-side keys to freq (if j > 0)
            // key = (l1*val[j-1] - S[j]) % k
            if (j > 0) {
                int i = j - 1;
                long long vi = runs[i].first % k;
                long long ci = runs[i].second;
                long long Si1 = S[i + 1] % k;
                for (long long l1 = 1; l1 <= ci; l1++) {
                    long long key = ((l1 * vi - Si1) % k + k) % k;
                    freq[key]++;
                }
            }
            
            // For run j, count pairs with all previous runs
            if (j > 0) {
                long long vj = runs[j].first % k;
                long long cj = runs[j].second;
                long long Sj = S[j] % k;
                for (long long l2 = 1; l2 <= cj; l2++) {
                    long long target = (-(Sj + l2 * vj) % k + k) % k;
                    if (freq.count(target)) {
                        ans += freq[target];
                    }
                }
            }
        }
        
        return ans;
    }
};
