// @leetcode id=1439 questionId=1550 slug=find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows lang=cpp site=leetcode.com title="Find the Kth Smallest Sum of a Matrix With Sorted Rows"
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums = {0};
        for (auto& row : mat) {
            vector<int> next;
            for (int s : sums) {
                for (int v : row) next.push_back(s + v);
            }
            sort(next.begin(), next.end());
            if ((int)next.size() > k) next.resize(k);
            sums = next;
        }
        return sums[k - 1];
    }
};
