// @leetcode id=2761 questionId=2873 slug=prime-pairs-with-target-sum lang=cpp site=leetcode.com title="Prime Pairs With Target Sum"
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> result;
        if (n < 4) return result;

        vector<bool> isComposite(n + 1, false);
        isComposite[0] = isComposite[1] = true;
        for (int i = 2; (long long)i * i <= n; i++) {
            if (isComposite[i]) continue;
            for (long long j = (long long)i * i; j <= n; j += i) isComposite[j] = true;
        }

        for (int x = 2; x <= n / 2; x++) {
            int y = n - x;
            if (!isComposite[x] && !isComposite[y]) result.push_back({x, y});
        }
        return result;
    }
};
