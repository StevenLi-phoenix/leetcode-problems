// @leetcode id=2747 questionId=2833 slug=count-zero-request-servers lang=cpp site=leetcode.com title="Count Zero Request Servers"
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<int> order(q);
        for (int i = 0; i < q; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> result(q);
        unordered_map<int, int> countInWindow;
        int active = 0;
        int left = 0, right = 0;
        int m = logs.size();

        for (int idx : order) {
            int hi = queries[idx];
            int lo = hi - x;

            while (right < m && logs[right][1] <= hi) {
                int sid = logs[right][0];
                if (countInWindow[sid]++ == 0) active++;
                right++;
            }
            while (left < right && logs[left][1] < lo) {
                int sid = logs[left][0];
                if (--countInWindow[sid] == 0) active--;
                left++;
            }

            result[idx] = n - active;
        }
        return result;
    }
};
