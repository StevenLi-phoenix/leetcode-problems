// @leetcode id=3998 questionId=3993 slug=transform-binary-string-using-subsequence-sort lang=cpp site=leetcode.com title="Transform Binary String Using Subsequence Sort"
class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> S(n + 1, 0);
        for (int i = 0; i < n; i++) {
            S[i + 1] = S[i] + (s[i] == '1');
        }
        int M = S[n];

        vector<bool> ans;
        for (const string& str : strs) {
            int fixedOnes = 0, k = 0;
            for (char c : str) {
                if (c == '1') fixedOnes++;
                else if (c == '?') k++;
            }
            int x = M - fixedOnes;

            if (x < 0 || x > k) {
                ans.push_back(false);
                continue;
            }

            int prefixOnes = 0, qSeen = 0;
            bool feasible = true;
            for (int i = 0; i < n; i++) {
                char c = str[i];
                if (c == '1') {
                    prefixOnes++;
                } else if (c == '?') {
                    if (qSeen >= k - x) prefixOnes++;
                    qSeen++;
                }
                if (prefixOnes > S[i + 1]) {
                    feasible = false;
                    break;
                }
            }
            ans.push_back(feasible);
        }

        return ans;
    }
};
