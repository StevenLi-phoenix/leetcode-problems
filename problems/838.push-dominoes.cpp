// @leetcode id=838 questionId=868 slug=push-dominoes lang=cpp site=leetcode.com title="Push Dominoes"
class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n = s.size();
        string result = s;
        int prev = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == '.') continue;
            char left = s[prev], right = s[i];
            if (left == right) {
                for (int j = prev + 1; j < i; j++) result[j] = left;
            } else if (left == 'R' && right == 'L') {
                int lo = prev + 1, hi = i - 1;
                while (lo < hi) {
                    result[lo++] = 'R';
                    result[hi--] = 'L';
                }
            }
            prev = i;
        }
        return result.substr(1, dominoes.size());
    }
};
