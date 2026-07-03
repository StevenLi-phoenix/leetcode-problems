// @leetcode id=502 questionId=502 slug=ipo lang=cpp site=leetcode.com title="IPO"
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return capital[a] < capital[b];
        });

        priority_queue<int> maxHeap;
        long long curCapital = w;
        int ptr = 0;

        for (int t = 0; t < k; ++t) {
            while (ptr < n && capital[idx[ptr]] <= curCapital) {
                maxHeap.push(profits[idx[ptr]]);
                ++ptr;
            }
            if (maxHeap.empty()) break;
            curCapital += maxHeap.top();
            maxHeap.pop();
        }
        return (int)curCapital;
    }
};
