// @leetcode id=2081 questionId=2202 slug=sum-of-k-mirror-numbers lang=cpp site=leetcode.com title="Sum of k-Mirror Numbers"
class Solution {
public:
    long long kMirror(int k, int n) {
        // Generate palindromes in base-k in increasing order
        // Check if they are also palindromes in base-10
        
        auto isPalin10 = [](long long x) -> bool {
            string s = to_string(x);
            string r = s;
            reverse(r.begin(), r.end());
            return s == r;
        };
        
        // Convert base-k palindrome (represented as half digits) to base-10
        // For odd length: half has ceil(len/2) digits
        // For even length: half has len/2 digits
        
        // Generate palindromes in base-k by length
        long long sum = 0;
        int count = 0;
        
        for (int len = 1; count < n; len++) {
            int halfLen = (len + 1) / 2;
            
            // half ranges from k^(halfLen-1) to k^halfLen - 1
            long long lo = 1;
            for (int i = 0; i < halfLen - 1; i++) lo *= k;
            long long hi = lo * k;
            
            for (long long h = lo; h < hi && count < n; h++) {
                // Build palindrome in base-k from h
                // Get digits of h in base-k
                vector<int> halfDigits;
                long long tmp = h;
                while (tmp > 0) {
                    halfDigits.push_back(tmp % k);
                    tmp /= k;
                }
                reverse(halfDigits.begin(), halfDigits.end());
                
                // Build full palindrome digits
                vector<int> digits = halfDigits;
                int start = (len % 2 == 0) ? (int)halfDigits.size() - 1 : (int)halfDigits.size() - 2;
                for (int i = start; i >= 0; i--) {
                    digits.push_back(halfDigits[i]);
                }
                
                // Convert to base-10
                long long val = 0;
                for (int d : digits) {
                    val = val * k + d;
                }
                
                if (isPalin10(val)) {
                    sum += val;
                    count++;
                }
            }
        }
        
        return sum;
    }
};
