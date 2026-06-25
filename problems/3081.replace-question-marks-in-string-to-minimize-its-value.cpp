// @leetcode id=3081 questionId=3354 slug=replace-question-marks-in-string-to-minimize-its-value lang=cpp site=leetcode.com title="Replace Question Marks in String to Minimize Its Value"
class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        
        // Count frequencies of non-'?' characters
        vector<int> freq(26, 0);
        for (char c : s) {
            if (c != '?') freq[c - 'a']++;
        }
        
        // For each '?', greedily pick the character with minimum frequency
        // Use min-heap of (freq, char_index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (int i = 0; i < 26; i++) {
            pq.push({freq[i], i});
        }
        
        // Collect replacement characters
        vector<char> replacements;
        for (char c : s) {
            if (c == '?') {
                auto [f, ci] = pq.top();
                pq.pop();
                replacements.push_back('a' + ci);
                pq.push({f + 1, ci});
            }
        }
        
        // Sort replacements for lex smallest assignment
        sort(replacements.begin(), replacements.end());
        
        // Fill '?' positions from left to right with sorted replacements
        int ri = 0;
        string result = s;
        for (char& c : result) {
            if (c == '?') {
                c = replacements[ri++];
            }
        }
        
        return result;
    }
};
