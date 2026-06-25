// @leetcode id=3412 questionId=3634 slug=find-mirror-score-of-a-string lang=cpp site=leetcode.com title="Find Mirror Score of a String"
class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        vector<stack<int>> stacks(26); // one stack per letter
        long long score = 0;
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            int mirrorC = 25 - c; // mirror of letter c
            
            if (!stacks[mirrorC].empty()) {
                int j = stacks[mirrorC].top();
                stacks[mirrorC].pop();
                score += i - j;
            } else {
                stacks[c].push(i);
            }
        }
        
        return score;
    }
};
