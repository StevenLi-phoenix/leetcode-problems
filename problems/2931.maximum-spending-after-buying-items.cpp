// @leetcode id=2931 questionId=3107 slug=maximum-spending-after-buying-items lang=cpp site=leetcode.com title="Maximum Spending After Buying Items"
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<int> all;
        for (auto& row : values) {
            for (int v : row) all.push_back(v);
        }
        sort(all.begin(), all.end());

        long long total = 0;
        for (int i = 0; i < (int)all.size(); i++) {
            total += (long long)all[i] * (i + 1);
        }

        return total;
    }
};
