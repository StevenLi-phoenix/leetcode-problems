// @leetcode id=3039 questionId=3308 slug=apply-operations-to-make-string-empty lang=cpp site=leetcode.com title="Apply Operations to Make String Empty"
class Solution {
public:
    string lastNonEmptyString(string s) {
        int freq[26] = {};
        int lastIdx[26] = {};
        
        for (int i = 0; i < (int)s.size(); i++) {
            freq[s[i] - 'a']++;
            lastIdx[s[i] - 'a'] = i;
        }
        
        int maxFreq = *max_element(freq, freq + 26);
        
        // Collect characters with maxFreq, in order of their last occurrence in s
        vector<pair<int,char>> candidates; // (lastIdx, char)
        for (int c = 0; c < 26; c++) {
            if (freq[c] == maxFreq) {
                candidates.push_back({lastIdx[c], (char)('a' + c)});
            }
        }
        
        sort(candidates.begin(), candidates.end());
        
        string result = "";
        for (auto& [idx, ch] : candidates) {
            result += ch;
        }
        return result;
    }
};
