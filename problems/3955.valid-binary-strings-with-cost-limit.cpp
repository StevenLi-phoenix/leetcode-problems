// @leetcode id=3955 questionId=4289 slug=valid-binary-strings-with-cost-limit lang=cpp site=leetcode.com title="Valid Binary Strings With Cost Limit"
class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> result;
        string cur(n, '0');

        function<void(int, int, bool)> dfs = [&](int i, int cost, bool prevOne) {
            if (cost > k) return;
            if (i == n) {
                result.push_back(cur);
                return;
            }

            cur[i] = '0';
            dfs(i + 1, cost, false);

            if (!prevOne) {
                cur[i] = '1';
                dfs(i + 1, cost + i, true);
                cur[i] = '0';
            }
        };

        dfs(0, 0, false);
        return result;
    }
};
