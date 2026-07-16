// @leetcode id=2343 questionId=2422 slug=query-kth-smallest-trimmed-number lang=cpp site=leetcode.com title="Query Kth Smallest Trimmed Number"
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int len = nums[0].size();
        vector<int> result;

        for (auto& q : queries) {
            int k = q[0], trim = q[1];
            vector<pair<string, int>> trimmed(n);
            for (int i = 0; i < n; i++) {
                trimmed[i] = {nums[i].substr(len - trim), i};
            }
            stable_sort(trimmed.begin(), trimmed.end(), [](const pair<string,int>& a, const pair<string,int>& b) {
                return a.first < b.first;
            });
            result.push_back(trimmed[k - 1].second);
        }
        return result;
    }
};
