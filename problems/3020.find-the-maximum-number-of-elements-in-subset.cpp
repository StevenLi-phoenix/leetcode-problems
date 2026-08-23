// @leetcode id=3020 questionId=3299 slug=find-the-maximum-number-of-elements-in-subset lang=cpp site=leetcode.com title="Find the Maximum Number of Elements in Subset"
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[(long long)x]++;
        
        int ans = 1;
        
        // Handle 1s separately
        if (freq.count(1)) {
            int cnt = freq[1];
            // Odd count: use all; even count: use count-1 (to make it odd)
            ans = max(ans, cnt % 2 == 1 ? cnt : cnt - 1);
        }
        
        // For x > 1: build chain x -> x^2 -> x^4 -> ...
        // Pairs contribute 2 elements each to the palindrome
        // Center contributes 1 element
        for (auto& [x, cnt] : freq) {
            if (x == 1) continue;
            
            long long cur = x;
            int pairs = 0;
            
            // Accumulate pairs
            while (cur <= 1000000000LL && freq.count(cur) && freq[cur] >= 2) {
                pairs++;
                cur = cur * cur;
            }
            
            // Try to use cur as center
            if (cur <= 1000000000LL && freq.count(cur) && freq[cur] >= 1) {
                ans = max(ans, 2 * pairs + 1);
            } else if (pairs > 0) {
                // Can't use cur as center; demote last pair to single center
                // Last pair level is cur/sqrt (which we don't track easily)
                // Actually: after the loop, pairs includes levels x, x^2, ..., x^(2^(pairs-1))
                // The last level (x^(2^(pairs-1))) has freq>=2, we used it as a pair
                // We can instead use just 1 copy of it as center
                // Result: (pairs-1) pairs + 1 center = 2*(pairs-1)+1
                ans = max(ans, 2 * (pairs - 1) + 1);
            }
        }
        
        return ans;
    }
};
