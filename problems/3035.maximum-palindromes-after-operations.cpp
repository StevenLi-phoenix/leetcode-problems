// @leetcode id=3035 questionId=3317 slug=maximum-palindromes-after-operations lang=cpp site=leetcode.com title="Maximum Palindromes After Operations"
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        // Count total frequency of all characters
        int freq[26] = {};
        for (auto& w : words) {
            for (char c : w) freq[c - 'a']++;
        }
        
        // Count total pairs available
        int totalPairs = 0;
        for (int i = 0; i < 26; i++) totalPairs += freq[i] / 2;
        
        // Get lengths of all words and sort ascending (greedy: fill shortest first)
        vector<int> lens;
        for (auto& w : words) lens.push_back(w.size());
        sort(lens.begin(), lens.end());
        
        int result = 0;
        for (int L : lens) {
            int need = L / 2;
            if (totalPairs >= need) {
                totalPairs -= need;
                result++;
            } else {
                break;
            }
        }
        return result;
    }
};
