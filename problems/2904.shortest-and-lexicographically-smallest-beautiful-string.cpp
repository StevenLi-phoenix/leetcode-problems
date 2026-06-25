// @leetcode id=2904 questionId=3150 slug=shortest-and-lexicographically-smallest-beautiful-string lang=cpp site=leetcode.com title="Shortest and Lexicographically Smallest Beautiful String"
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string result = "";
        int minLen = INT_MAX;
        
        // Try all substrings with sliding window
        // For each left position, find rightmost position with exactly k 1s
        for (int left = 0; left < n; left++) {
            int ones = 0;
            for (int right = left; right < n; right++) {
                if (s[right] == '1') ones++;
                if (ones == k) {
                    // Found a beautiful substring s[left..right]
                    int len = right - left + 1;
                    string sub = s.substr(left, len);
                    
                    if (len < minLen || (len == minLen && sub < result)) {
                        minLen = len;
                        result = sub;
                    }
                    break; // no need to extend further for this left
                }
            }
        }
        
        return result;
    }
};
