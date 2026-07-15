// @leetcode id=932 questionId=968 slug=beautiful-array lang=cpp site=leetcode.com title="Beautiful Array"
class Solution {
public:
    vector<int> beautifulArray(int n) {
        return solve(n);
    }

private:
    unordered_map<int, vector<int>> memo;

    vector<int> solve(int n) {
        if (n == 1) return {1};
        auto it = memo.find(n);
        if (it != memo.end()) return it->second;

        vector<int> odds = solve((n + 1) / 2);
        vector<int> evens = solve(n / 2);

        vector<int> result;
        for (int x : odds) result.push_back(2 * x - 1);
        for (int x : evens) result.push_back(2 * x);

        memo[n] = result;
        return result;
    }
};
