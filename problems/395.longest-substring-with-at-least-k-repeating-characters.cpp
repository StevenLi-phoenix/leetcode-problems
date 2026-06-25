// @leetcode id=395 questionId=395 slug=longest-substring-with-at-least-k-repeating-characters lang=cpp site=leetcode.com title="Longest Substring with At Least K Repeating Characters"
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length() < k) return 0;
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        for (auto& [c, f] : freq) {
            if (f < k) {
                int maxLen = 0;
                for (string substr : split(s, c)) {
                    maxLen = max(maxLen, longestSubstring(substr, k));
                }
                return maxLen;
            }
        }
        
        return s.length();
    }
    
private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> result;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delimiter)) {
            if (!item.empty()) {
                result.push_back(item);
            }
        }
        return result;
    }
};
