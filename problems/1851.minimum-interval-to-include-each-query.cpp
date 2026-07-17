// @leetcode id=1851 questionId=1977 slug=minimum-interval-to-include-each-query lang=cpp site=leetcode.com title="Minimum Interval to Include Each Query"
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // (size, right)
        vector<int> answer(q, -1);

        int idx = 0;
        int n = intervals.size();

        for (int qi : order) {
            int query = queries[qi];

            while (idx < n && intervals[idx][0] <= query) {
                int size = intervals[idx][1] - intervals[idx][0] + 1;
                pq.push({size, intervals[idx][1]});
                idx++;
            }

            while (!pq.empty() && pq.top().second < query) pq.pop();

            if (!pq.empty()) answer[qi] = pq.top().first;
        }

        return answer;
    }
};
