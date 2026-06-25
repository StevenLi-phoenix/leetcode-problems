// @leetcode id=3747 questionId=4054 slug=count-distinct-integers-after-removing-zeros lang=cpp site=leetcode.com title="Count Distinct Integers After Removing Zeros"
class Solution {
public:
    long long countDistinct(long long n) {
        // Count integers in [1, n] with no zero digit
        // These are exactly the distinct values of remove_zeros(x) for x in [1,n]
        string s = to_string(n);
        int len = s.size();
        long long result = 0;
        
        // Count all numbers with fewer digits than len, with no zeros
        // d-digit numbers with no zeros: 9^d
        long long pw = 9;
        for (int d = 1; d < len; d++) {
            result += pw;
            pw *= 9;
        }
        
        // Count len-digit numbers with no zeros that are <= n
        // Digit by digit
        bool tight = true;
        for (int i = 0; i < len && tight; i++) {
            int digit = s[i] - '0';
            // We can choose from 1 (or previous+1 if tight) to digit-1 freely
            int lo = (i == 0) ? 1 : 1; // first digit can't be 0 anyway
            // Digits that are < digit and >= 1
            int free_choices = digit - 1; // digits 1..digit-1
            if (free_choices > 0) {
                // For each free choice, remaining positions can be anything 1-9
                long long ways = 1;
                for (int j = i + 1; j < len; j++) ways *= 9;
                result += (long long)free_choices * ways;
            }
            
            // If digit == 0, we can't continue with tight constraint
            if (digit == 0) {
                tight = false;
            }
            // else continue tight
        }
        // If we survived all digits with tight=true, n itself has no zeros
        if (tight) result++;
        
        return result;
    }
};
