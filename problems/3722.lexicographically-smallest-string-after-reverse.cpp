// @leetcode id=3722 questionId=4073 slug=lexicographically-smallest-string-after-reverse lang=cpp site=leetcode.com title="Lexicographically Smallest String After Reverse"
class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string best = s;
        
        // Try reversing first k characters
        for (int k = 1; k <= n; k++) {
            string t = s;
            reverse(t.begin(), t.begin() + k);
            if (t < best) best = t;
        }
        
        // Try reversing last k characters
        for (int k = 1; k <= n; k++) {
            string t = s;
            reverse(t.end() - k, t.end());
            if (t < best) best = t;
        }
        
        return best;
    }
};
