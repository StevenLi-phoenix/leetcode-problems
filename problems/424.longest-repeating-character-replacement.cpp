// @leetcode id=424 questionId=424 slug=longest-repeating-character-replacement lang=cpp site=leetcode.com title="Longest Repeating Character Replacement"
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);
        int left = 0, maxFreq = 0, result = 0;
        
        for (int right = 0; right < n; right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            
            // If current window is invalid, shrink from left
            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};
