// @leetcode id=1249 questionId=1371 slug=minimum-remove-to-make-valid-parentheses lang=cpp site=leetcode.com title="Minimum Remove to Make Valid Parentheses"
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> toRemove;
        stack<int> st;
        
        // Find all indices to remove
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    toRemove.insert(i);
                } else {
                    st.pop();
                }
            }
        }
        
        // Mark remaining unmatched opening parentheses for removal
        while (!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }
        
        // Build result string
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (toRemove.find(i) == toRemove.end()) {
                result += s[i];
            }
        }
        
        return result;
    }
};
