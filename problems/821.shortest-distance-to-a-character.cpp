// @leetcode id=821 questionId=841 slug=shortest-distance-to-a-character lang=cpp site=leetcode.com title="Shortest Distance to a Character"
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, INT_MAX / 2);

        int last = -n * 2;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) last = i;
            ans[i] = i - last;
        }

        last = n * 2;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) last = i;
            ans[i] = min(ans[i], last - i);
        }
        return ans;
    }
};
