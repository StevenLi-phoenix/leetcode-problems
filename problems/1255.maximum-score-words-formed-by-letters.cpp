// @leetcode id=1255 questionId=1381 slug=maximum-score-words-formed-by-letters lang=cpp site=leetcode.com title="Maximum Score Words Formed by Letters"
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        
        // Count available letters
        int avail[26] = {};
        for (char c : letters) avail[c - 'a']++;
        
        int ans = 0;
        
        // Enumerate all 2^n subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt[26] = {};
            int total = 0;
            bool valid = true;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    for (char c : words[i]) {
                        cnt[c - 'a']++;
                    }
                }
            }
            
            for (int c = 0; c < 26; c++) {
                if (cnt[c] > avail[c]) { valid = false; break; }
                total += cnt[c] * score[c];
            }
            
            if (valid) ans = max(ans, total);
        }
        
        return ans;
    }
};
