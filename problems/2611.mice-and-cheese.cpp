// @leetcode id=2611 questionId=2725 slug=mice-and-cheese lang=cpp site=leetcode.com title="Mice and Cheese"
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return reward1[a] - reward2[a] > reward1[b] - reward2[b];
        });

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += (i < k) ? reward1[idx[i]] : reward2[idx[i]];
        }
        return (int)total;
    }
};
