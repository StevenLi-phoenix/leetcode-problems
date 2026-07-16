// @leetcode id=1834 questionId=1962 slug=single-threaded-cpu lang=cpp site=leetcode.com title="Single-Threaded CPU"
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0];
        });

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<int> result;
        result.reserve(n);

        long long time = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty() && time < tasks[idx[i]][0]) {
                time = tasks[idx[i]][0];
            }
            while (i < n && tasks[idx[i]][0] <= time) {
                pq.push({tasks[idx[i]][1], idx[i]});
                i++;
            }
            auto [proc, taskIdx] = pq.top(); pq.pop();
            time += proc;
            result.push_back(taskIdx);
        }
        return result;
    }
};
