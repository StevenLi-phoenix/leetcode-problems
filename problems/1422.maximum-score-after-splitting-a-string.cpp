// @leetcode id=1422 questionId=1537 slug=maximum-score-after-splitting-a-string lang=cpp site=leetcode.com title="Maximum Score After Splitting a String"
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) if (c == '1') totalOnes++;
        
        int maxScore = 0;
        int leftZeros = 0, rightOnes = totalOnes;
        
        // Try each split point i from 1 to n-1 (left = s[0..i-1], right = s[i..n-1])
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') leftZeros++;
            else rightOnes--;
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        
        return maxScore;
    }
};
