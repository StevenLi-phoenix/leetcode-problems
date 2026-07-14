// @leetcode id=3228 questionId=3493 slug=maximum-number-of-operations-to-move-ones-to-the-end lang=cpp site=leetcode.com title="Maximum Number of Operations to Move Ones to the End"
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        long long ans = 0, onesCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                onesCount++;
            } else if (i == 0 || s[i - 1] == '1') {
                // start of a new zero-run: every one seen so far crosses it once
                ans += onesCount;
            }
        }
        return (int)ans;
    }
};
