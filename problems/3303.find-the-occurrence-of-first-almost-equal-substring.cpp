// @leetcode id=3303 questionId=3580 slug=find-the-occurrence-of-first-almost-equal-substring lang=cpp site=leetcode.com title="Find the Occurrence of First Almost Equal Substring"
class Solution {
public:
    // Z-function: z[i] = length of longest substring starting from s[i] 
    // that is also a prefix of s
    vector<int> zFunction(const string& s) {
        int n = s.size();
        vector<int> z(n, 0);
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }
        return z;
    }
    
    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        
        // Forward Z-function: how many chars match from the start of pattern
        string fwd = pattern + "#" + s;
        vector<int> zFwd = zFunction(fwd);
        // prefixMatch[i] = length of match starting at s[i] from start of pattern
        // zFwd[m+1+i] = match length, capped at m
        
        // Reverse Z-function: how many chars match from the end of pattern  
        string rev = string(pattern.rbegin(), pattern.rend()) + "#" + string(s.rbegin(), s.rend());
        vector<int> zRev = zFunction(rev);
        // suffixMatch[i] = length of match ending at s[i] from end of pattern
        
        for (int i = 0; i <= n - m; i++) {
            // prefixLen: how many chars match at start
            int prefixLen = min((int)zFwd[m + 1 + i], m);
            if (prefixLen == m) return i; // exact match
            
            // Check if at most 1 mismatch
            // After matching prefixLen chars, the mismatch is at position prefixLen
            // Then we need the remaining m - prefixLen - 1 chars to match from the end
            int suffixStart = n - 1 - (i + m - 1); // position in reversed s
            int suffixLen = min((int)zRev[m + 1 + suffixStart], m);
            
            if (prefixLen + suffixLen >= m - 1) return i;
        }
        return -1;
    }
};
