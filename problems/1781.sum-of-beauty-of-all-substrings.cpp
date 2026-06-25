// @leetcode id=1781 questionId=1890 slug=sum-of-beauty-of-all-substrings lang=cpp site=leetcode.com title="Sum of Beauty of All Substrings"
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {};
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                maxFreq = max(maxFreq, freq[s[j] - 'a']);
                int minFreq = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) minFreq = min(minFreq, freq[k]);
                }
                ans += maxFreq - minFreq;
            }
        }
        return ans;
    }
};
