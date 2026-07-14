// @leetcode id=216 questionId=216 slug=combination-sum-iii lang=cpp site=leetcode.com title="Combination Sum III"
class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int k, int remaining) {
        if ((int)current.size() == k) {
            if (remaining == 0) result.push_back(current);
            return;
        }
        for (int d = start; d <= 9; d++) {
            if (d > remaining) break;
            current.push_back(d);
            backtrack(d + 1, k, remaining - d);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        return result;
    }
};
