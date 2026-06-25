// @leetcode id=1239 questionId=1360 slug=maximum-length-of-a-concatenated-string-with-unique-characters lang=cpp site=leetcode.com title="Maximum Length of a Concatenated String with Unique Characters"
class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Filter out strings with duplicate characters
        vector<string> valid;
        for (const string& s : arr) {
            unordered_set<char> chars(s.begin(), s.end());
            if (chars.size() == s.length()) {
                valid.push_back(s);
            }
        }
        
        int maxLen = 0;
        unordered_set<char> current;
        dfs(valid, 0, current, maxLen);
        return maxLen;
    }
    
private:
    void dfs(vector<string>& arr, int idx, unordered_set<char>& current, int& maxLen) {
        maxLen = max(maxLen, (int)current.size());
        
        if (idx == arr.size()) return;
        
        for (int i = idx; i < arr.size(); i++) {
            const string& s = arr[i];
            
            // Check if we can add this string
            bool canAdd = true;
            for (char c : s) {
                if (current.count(c)) {
                    canAdd = false;
                    break;
                }
            }
            
            if (canAdd) {
                // Add characters
                for (char c : s) {
                    current.insert(c);
                }
                
                dfs(arr, i + 1, current, maxLen);
                
                // Remove characters
                for (char c : s) {
                    current.erase(c);
                }
            }
        }
    }
};
