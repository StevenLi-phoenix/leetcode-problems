// @leetcode id=2478 questionId=2569 slug=number-of-beautiful-partitions lang=cpp site=leetcode.com title="Number of Beautiful Partitions"
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        const int MOD = 1e9 + 7;
        
        auto isPrime = [](char c) {
            return c == '2' || c == '3' || c == '5' || c == '7';
        };
        
        // Check if first char is prime and last char is non-prime
        if (!isPrime(s[0]) || isPrime(s[n-1])) return 0;
        
        // dp[i][j] = number of ways to partition s[0..i-1] into j parts
        // Use 1-indexed for s positions
        // A valid split point at position i means s[i] starts a new partition
        // and s[i-1] ends the previous partition (non-prime)
        
        // dp[j][i] = ways to form j partitions ending at index i (1-indexed)
        // Transition: dp[j][i] = sum of dp[j-1][t] for all valid t
        //   where t <= i - minLength, s[t] is non-prime (end of prev part), s[t+1] is prime (start of new)
        
        // dp[i][j] = number of beautiful ways to split s[0..i-1] into j parts
        // dp[i][j] = sum over t of dp[t][j-1], where:
        //   - i - t >= minLength (current part has enough length)
        //   - s[t] is non-prime (prev part ends well)  
        //   - s[t+1-1] = s[t] wait let me re-index
        
        // Let's use: dp[j][i] = ways to partition s[0..i-1] into j beautiful parts
        // For j=1: dp[1][i] = 1 if isPrime(s[0]) && !isPrime(s[i-1]) && i >= minLength, else 0
        // For j>1: dp[j][i] = sum_{t=j*minLength}^{i-minLength} dp[j-1][t] 
        //   where !isPrime(s[t-1]) && isPrime(s[t])
        //   (last part is s[t..i-1], starts at t with prime, has length i-t >= minLength)
        //   previous parts end at t-1 (non-prime), next starts at t (prime)
        
        // Use prefix sums for optimization
        vector<vector<long long>> dp(k+1, vector<long long>(n+1, 0));
        vector<long long> prefix(n+1, 0);
        
        // Base: j=1
        // dp[1][i] = 1 if s[0] is prime and s[i-1] is non-prime and i >= minLength
        // We already checked s[0] is prime
        for (int i = minLength; i <= n; i++) {
            if (!isPrime(s[i-1])) {
                dp[1][i] = 1;
            }
        }
        
        // Fill dp for j = 2..k
        for (int j = 2; j <= k; j++) {
            // Compute prefix sum of dp[j-1] at positions where s[t-1] is non-prime AND s[t] is prime
            // i.e., can split between position t-1 and t
            prefix[0] = 0;
            long long runSum = 0;
            for (int t = 1; t <= n; t++) {
                // Can we add dp[j-1][t] to prefix? Yes if position t is a valid split point:
                // s[t-1] is non-prime (end of prev part) and s[t] is prime (start of new part)
                // and t >= (j-1)*minLength
                if (t >= (j-1)*minLength && !isPrime(s[t-1]) && (t < n) && isPrime(s[t])) {
                    runSum = (runSum + dp[j-1][t]) % MOD;
                }
                prefix[t] = runSum;
            }
            
            for (int i = j * minLength; i <= n; i++) {
                // Last part is s[?..i-1], must have length >= minLength
                // So last part starts at position <= i - minLength (0-indexed), i.e., index i-minLength (1-indexed start)
                // s[i-1] must be non-prime (we're computing dp[j][i])
                if (!isPrime(s[i-1])) {
                    // Sum dp[j-1][t] for t from (j-1)*minLength to i-minLength
                    // where s[t] is prime and s[t-1] is non-prime
                    // prefix[i-minLength] gives us the running sum up to t = i-minLength
                    dp[j][i] = prefix[i - minLength];
                }
            }
        }
        
        return dp[k][n];
    }
};
