// @leetcode id=1331 questionId=1256 slug=rank-transform-of-an-array lang=cpp site=leetcode.com title="Rank Transform of an Array"
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        unordered_map<int,int> rank;
        for (int i = 0; i < (int)sorted.size(); ++i) {
            rank[sorted[i]] = i + 1;
        }
        vector<int> ans;
        ans.reserve(arr.size());
        for (int x : arr) {
            ans.push_back(rank[x]);
        }
        return ans;
    }
};
