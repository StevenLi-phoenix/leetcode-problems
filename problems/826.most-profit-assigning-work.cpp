// @leetcode id=826 questionId=853 slug=most-profit-assigning-work lang=cpp site=leetcode.com title="Most Profit Assigning Work"
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return difficulty[a] < difficulty[b]; });
        sort(worker.begin(), worker.end());

        long long total = 0;
        int j = 0, bestProfit = 0;
        for (int w : worker) {
            while (j < n && difficulty[idx[j]] <= w) {
                bestProfit = max(bestProfit, profit[idx[j]]);
                j++;
            }
            total += bestProfit;
        }
        return (int)total;
    }
};
