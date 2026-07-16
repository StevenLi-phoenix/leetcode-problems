// @leetcode id=1177 questionId=1281 slug=can-make-palindrome-from-substring lang=cpp site=leetcode.com title="Can Make Palindrome from Substring"
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<array<int, 26>> prefix(n + 1);
        prefix[0].fill(0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            prefix[i + 1][s[i] - 'a']++;
        }

        vector<bool> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            int left = q[0], right = q[1], k = q[2];
            int oddCount = 0;
            for (int c = 0; c < 26; c++) {
                int cnt = prefix[right + 1][c] - prefix[left][c];
                if (cnt % 2 != 0) oddCount++;
            }
            result.push_back(oddCount / 2 <= k);
        }
        return result;
    }
};
