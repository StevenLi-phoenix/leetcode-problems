// @leetcode id=2014 questionId=2140 slug=longest-subsequence-repeated-k-times lang=cpp site=leetcode.com title="Longest Subsequence Repeated k Times"
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        // The n < k*8 constraint bounds any valid candidate to length <=7,
        // so BFS by length, extending only candidates that are already a
        // valid k-repeated subsequence (a candidate that fails can never
        // be fixed by appending more characters).
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;

        auto isKRepeated = [&](const string& seq) {
            int pos = 0;
            int need = seq.size() * k;
            for (char c : s) {
                if (pos < need && c == seq[pos % seq.size()]) pos++;
            }
            return pos >= need;
        };

        vector<char> validChars;
        for (int c = 25; c >= 0; c--) if (count[c] >= k) validChars.push_back('a' + c);

        queue<string> q;
        for (char c : validChars) q.push(string(1, c));

        string ans;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur.size() > ans.size() || (cur.size() == ans.size() && cur > ans)) ans = cur;

            for (char c : validChars) {
                string candidate = cur + c;
                if (isKRepeated(candidate)) q.push(candidate);
            }
        }
        return ans;
    }
};
