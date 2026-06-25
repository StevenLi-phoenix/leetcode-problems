// @leetcode id=866 questionId=897 slug=prime-palindrome lang=cpp site=leetcode.com title="Prime Palindrome"
class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; (long long)i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }
    
    // Generate palindrome from first half
    // For odd-length 2k+1: half has k+1 digits
    // e.g., half = 12, digits=5 -> 12321
    int makePalindrome(int half, int digits) {
        string s = to_string(half);
        // Pad with zeros to make length (digits+1)/2
        // Actually half already provides the first ceil(digits/2) digits
        string rev = s;
        reverse(rev.begin(), rev.end());
        // For odd length, skip middle digit in reverse
        string pal = s + rev.substr(1);
        return stoi(pal);
    }
    
    int primePalindrome(int n) {
        // Special cases for small n
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;
        
        // Generate odd-length palindromes
        // 1-digit: 1,2,3,4,5,6,7,8,9
        // 3-digit: 100-999 first half = 10-99 (wait: 3 digits, first 2 digits form half)
        // 5-digit: first 3 digits
        // ...
        // For odd length 2k+1, half is k+1 digits, range [10^k, 10^(k+1) - 1]
        
        for (int len = 1; len <= 9; len += 2) {
            // Generate palindromes of this length
            int halfLen = (len + 1) / 2;
            int halfStart = (halfLen == 1) ? 1 : pow(10, halfLen - 1);
            int halfEnd = pow(10, halfLen) - 1;
            
            for (int half = halfStart; half <= halfEnd; half++) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());
                string palStr = s + rev.substr(1);
                int pal = stoi(palStr);
                if (pal >= n && isPrime(pal)) return pal;
            }
        }
        
        return -1;
    }
};
