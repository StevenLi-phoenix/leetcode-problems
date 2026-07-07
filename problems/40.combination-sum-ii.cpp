// @leetcode id=40 questionId=40 slug=combination-sum-ii lang=cpp site=leetcode.com title="Combination Sum II"
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;

        function<void(int, int)> dfs = [&](int start, int remaining) {
            if (remaining == 0) {
                result.push_back(current);
                return;
            }

            for (int i = start; i < (int)candidates.size(); ++i) {
                if (candidates[i] > remaining) break;
                if (i > start && candidates[i] == candidates[i - 1]) continue;

                current.push_back(candidates[i]);
                dfs(i + 1, remaining - candidates[i]);
                current.pop_back();
            }
        };

        dfs(0, target);
        return result;
    }
};
