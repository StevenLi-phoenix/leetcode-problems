// @leetcode id=2262 questionId=2340 slug=total-appeal-of-a-string lang=cpp site=leetcode.com title="Total Appeal of A String"
class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<int> lastSeen(26, -1);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            total += (long long)(i - lastSeen[c]) * (n - i);
            lastSeen[c] = i;
        }
        return total;
    }
};
