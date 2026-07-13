// @leetcode id=1906 questionId=2034 slug=minimum-absolute-difference-queries lang=cpp site=leetcode.com title="Minimum Absolute Difference Queries"
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int MAXV = 100;
        vector<vector<int>> prefix(n + 1, vector<int>(MAXV + 1, 0));
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            prefix[i + 1][nums[i]]++;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int prevVal = -1, best = INT_MAX;
            for (int v = 1; v <= MAXV; v++) {
                if (prefix[r + 1][v] - prefix[l][v] > 0) {
                    if (prevVal != -1) best = min(best, v - prevVal);
                    prevVal = v;
                }
            }
            ans.push_back(best == INT_MAX ? -1 : best);
        }
        return ans;
    }
};
