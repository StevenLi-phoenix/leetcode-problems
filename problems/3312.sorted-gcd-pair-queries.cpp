// @leetcode id=3312 questionId=3583 slug=sorted-gcd-pair-queries lang=cpp site=leetcode.com title="Sorted GCD Pair Queries"
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // cnt[v] = frequency of v in nums
        vector<long long> cnt(maxVal + 1, 0);
        for (int x : nums) cnt[x]++;
        
        // cntDiv[g] = count of elements divisible by g
        vector<long long> cntDiv(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            for (int mult = g; mult <= maxVal; mult += g) {
                cntDiv[g] += cnt[mult];
            }
        }
        
        // cntPairs[g] = number of pairs (i,j) where both nums[i] and nums[j] are divisible by g
        // = C(cntDiv[g], 2)
        // exactPairs[g] = pairs where GCD is exactly g
        // Using inclusion exclusion: exactPairs[g] = cntPairs[g] - sum(exactPairs[k*g]) for k >= 2
        vector<long long> exactPairs(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; g--) {
            exactPairs[g] = cntDiv[g] * (cntDiv[g] - 1) / 2;
            for (int mult = 2 * g; mult <= maxVal; mult += g) {
                exactPairs[g] -= exactPairs[mult];
            }
        }
        
        // Build prefix sum: prefixPairs[g] = total pairs with GCD <= g
        vector<long long> prefixPairs(maxVal + 2, 0);
        for (int g = 1; g <= maxVal; g++) {
            prefixPairs[g] = prefixPairs[g - 1] + exactPairs[g];
        }
        
        // For each query, binary search for the GCD value
        int q = queries.size();
        vector<int> answer(q);
        for (int i = 0; i < q; i++) {
            long long target = queries[i]; // 0-indexed
            // Find smallest g such that prefixPairs[g] > target
            int lo = 1, hi = maxVal, res = maxVal;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefixPairs[mid] > target) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            answer[i] = res;
        }
        
        return answer;
    }
};
