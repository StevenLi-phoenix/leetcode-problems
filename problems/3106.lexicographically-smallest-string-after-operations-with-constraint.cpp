// @leetcode id=3106 questionId=3346 slug=lexicographically-smallest-string-after-operations-with-constraint lang=cpp site=leetcode.com title="Lexicographically Smallest String After Operations With Constraint"
class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string result = s;
        
        for (int i = 0; i < n && k > 0; i++) {
            int c = s[i] - 'a';
            // Distance from c to 'a' is min(c, 26-c) in cyclic order
            // But we want to go towards 'a', so dist = min(c, 26-c)
            int dist = min(c, 26 - c);
            
            if (dist <= k) {
                // Can change to 'a'
                k -= dist;
                result[i] = 'a';
            } else {
                // Change as much as possible
                // Going left (towards 'a'): reduce by k
                // Going right (away from 'a'): increase by k
                // We want the smallest, so go left: c - k
                result[i] = 'a' + (c - k);
                k = 0;
            }
        }
        
        return result;
    }
};
