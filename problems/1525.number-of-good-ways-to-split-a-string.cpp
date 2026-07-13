// @leetcode id=1525 questionId=1632 slug=number-of-good-ways-to-split-a-string lang=cpp site=leetcode.com title="Number of Good Ways to Split a String"
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> leftDistinct(n);
        {
            int freq[26] = {}, distinct = 0;
            for (int i = 0; i < n; i++) {
                if (freq[s[i] - 'a']++ == 0) distinct++;
                leftDistinct[i] = distinct;
            }
        }

        int rightDistinct = 0, count = 0;
        int freq[26] = {};
        for (int i = n - 1; i >= 1; i--) {
            if (freq[s[i] - 'a']++ == 0) rightDistinct++;
            if (leftDistinct[i - 1] == rightDistinct) count++;
        }
        return count;
    }
};
