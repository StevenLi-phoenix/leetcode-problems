// @leetcode id=77 questionId=77 slug=combinations lang=cpp site=leetcode.com title="Combinations"
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        function<void(int)> dfs = [&](int start) {
            if ((int)current.size() == k) {
                result.push_back(current);
                return;
            }
            int remaining = k - current.size();
            for (int i = start; i <= n - remaining + 1; ++i) {
                current.push_back(i);
                dfs(i + 1);
                current.pop_back();
            }
        };

        dfs(1);
        return result;
    }
};
