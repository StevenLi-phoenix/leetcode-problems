// @leetcode id=3614 questionId=3939 slug=process-string-with-special-operations-ii lang=cpp site=leetcode.com title="Process String with Special Operations II"
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        
        // Forward pass: compute length after each operation
        // lengths[i] = length of result after processing s[0..i]
        vector<long long> lengths(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '*') {
                lengths[i + 1] = max(0LL, lengths[i] - 1);
            } else if (c == '#') {
                // Cap at 2e15 to avoid overflow (k <= 1e15)
                lengths[i + 1] = min(lengths[i] * 2, (long long)2e15);
            } else if (c == '%') {
                lengths[i + 1] = lengths[i];
            } else {
                // lowercase letter
                lengths[i + 1] = lengths[i] + 1;
            }
        }
        
        // Check if k is out of bounds
        if (k >= lengths[n]) return '.';
        
        // Backward pass: trace k back through operations
        long long pos = k;
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long len_before = lengths[i];  // length before this op
            long long len_after  = lengths[i + 1]; // length after this op
            
            if (c == '*') {
                // '*' removed the last char: length went from len_before to len_before-1
                // pos was valid in after-state, it's the same position in before-state
                // (the removed char was at index len_before-1, which can't be pos since
                //  pos < len_after = len_before-1, so pos < len_before-1 < len_before)
                // pos unchanged
            } else if (c == '#') {
                // '#' doubled: length went from len_before to len_before*2
                // pos in [0, len_before*2): if pos >= len_before, it's in second copy
                if (len_before > 0) {
                    pos = pos % len_before;
                }
            } else if (c == '%') {
                // '%' reversed: length unchanged
                // pos in reversed string -> pos in original = (len_before - 1 - pos)
                pos = len_before - 1 - pos;
            } else {
                // lowercase letter: appended at index len_before
                // if pos == len_before, this IS the character
                if (pos == len_before) {
                    return c;
                }
                // else pos was already in the string before, unchanged
            }
        }
        
        // Should not reach here if input is valid
        return '.';
    }
};
