// @leetcode id=3470 questionId=3783 slug=permutations-iv lang=cpp site=leetcode.com title="Permutations IV"
class Solution {
public:
    // Count alternating permutations with rem_odd odd numbers and rem_even even numbers,
    // where the next element must have parity nextIsOdd (true=odd, false=even)
    // Cap at cap to avoid overflow
    long long countPerms(int rem_odd, int rem_even, bool nextIsOdd, long long cap) {
        if (rem_odd == 0 && rem_even == 0) return 1;
        if (nextIsOdd && rem_odd == 0) return 0;
        if (!nextIsOdd && rem_even == 0) return 0;
        
        long long result;
        if (nextIsOdd) {
            // Choose one of rem_odd odds, then continue with even
            result = (long long)rem_odd * countPerms(rem_odd - 1, rem_even, false, cap / rem_odd + 1);
        } else {
            // Choose one of rem_even evens, then continue with odd
            result = (long long)rem_even * countPerms(rem_odd, rem_even - 1, true, cap / rem_even + 1);
        }
        return min(result, cap);
    }
    
    vector<int> permute(int n, long long k) {
        int num_odd = (n + 1) / 2;  // count of odd numbers in [1..n]
        int num_even = n / 2;        // count of even numbers in [1..n]
        
        // Check total count
        // A valid alternating perm can start with odd (if num_odd >= num_even) or even
        long long total = 0;
        // Starting with odd
        long long start_odd = countPerms(num_odd, num_even, true, (long long)2e15);
        // Starting with even
        long long start_even = countPerms(num_odd, num_even, false, (long long)2e15);
        total = start_odd + start_even;
        if (total < k) return {};
        
        // Track available odds and evens
        vector<int> odds, evens;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) odds.push_back(i);
            else evens.push_back(i);
        }
        
        vector<int> result;
        int rem_odd = num_odd, rem_even = num_even;
        
        for (int pos = 0; pos < n; pos++) {
            // Try each available number in sorted order
            // First determine what parities are possible at this position
            // (based on previous element's parity if pos > 0)
            
            // Try all available numbers (sorted)
            vector<int> available;
            for (int x : odds) available.push_back(x);
            for (int x : evens) available.push_back(x);
            sort(available.begin(), available.end());
            
            bool found = false;
            for (int num : available) {
                bool isOdd = (num % 2 == 1);
                
                // Check alternating constraint with previous element
                if (pos > 0) {
                    bool prevOdd = (result.back() % 2 == 1);
                    if (isOdd == prevOdd) continue; // Same parity - skip
                }
                
                // Count permutations if we place num here
                int new_rem_odd = rem_odd - (isOdd ? 1 : 0);
                int new_rem_even = rem_even - (isOdd ? 0 : 1);
                bool nextIsOdd = !isOdd; // next must alternate
                
                long long cnt;
                if (new_rem_odd == 0 && new_rem_even == 0) {
                    cnt = 1;
                } else {
                    cnt = countPerms(new_rem_odd, new_rem_even, nextIsOdd, (long long)2e15);
                }
                
                if (cnt >= k) {
                    result.push_back(num);
                    if (isOdd) odds.erase(find(odds.begin(), odds.end(), num));
                    else evens.erase(find(evens.begin(), evens.end(), num));
                    rem_odd = new_rem_odd;
                    rem_even = new_rem_even;
                    found = true;
                    break;
                } else {
                    k -= cnt;
                }
            }
            if (!found) return {}; // shouldn't happen
        }
        
        return result;
    }
};
