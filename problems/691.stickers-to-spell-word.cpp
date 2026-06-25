// @leetcode id=691 questionId=691 slug=stickers-to-spell-word lang=cpp site=leetcode.com title="Stickers to Spell Word"
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        int total = 1 << n;
        vector<int> dp(total, INT_MAX);
        dp[0] = 0;
        
        for (int mask = 0; mask < total; mask++) {
            if (dp[mask] == INT_MAX) continue;
            // For each sticker, apply it starting from first uncovered char
            // Find first uncovered position
            int first = -1;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) { first = i; break; }
            }
            if (first == -1) continue;
            
            for (auto& s : stickers) {
                // Count chars in sticker
                int cnt[26] = {};
                for (char c : s) cnt[c-'a']++;
                
                // Apply sticker to current mask
                int newMask = mask;
                int tmp[26] = {};
                memcpy(tmp, cnt, sizeof(cnt));
                // Only add sticker if it contains target[first]
                if (!tmp[target[first]-'a']) continue;
                
                for (int i = 0; i < n; i++) {
                    if (!(newMask & (1 << i))) {
                        int c = target[i] - 'a';
                        if (tmp[c] > 0) {
                            tmp[c]--;
                            newMask |= (1 << i);
                        }
                    }
                }
                if (dp[newMask] > dp[mask] + 1)
                    dp[newMask] = dp[mask] + 1;
            }
        }
        
        return dp[total-1] == INT_MAX ? -1 : dp[total-1];
    }
};
