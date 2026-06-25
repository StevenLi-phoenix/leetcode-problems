// @leetcode id=3085 questionId=3360 slug=minimum-deletions-to-make-string-k-special lang=cpp site=leetcode.com title="Minimum Deletions to Make String K-Special"
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;
        
        vector<int> f;
        for (int x : freq) if (x > 0) f.push_back(x);
        sort(f.begin(), f.end());
        
        int n = f.size();
        int ans = INT_MAX;
        
        // Try each frequency as the minimum allowed frequency
        // prefix sum to quickly compute deletions
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + f[i];
        
        for (int i = 0; i < n; i++) {
            int min_freq = f[i];
            // Delete all chars with freq < min_freq (those before i)
            int del = prefix[i];
            
            // For chars with freq > min_freq + k, trim excess
            for (int j = i; j < n; j++) {
                if (f[j] > min_freq + k) {
                    del += f[j] - (min_freq + k);
                }
            }
            ans = min(ans, del);
        }
        
        // Also try deleting everything except one frequency group
        // Already handled by i = 0 case
        
        return ans;
    }
};
