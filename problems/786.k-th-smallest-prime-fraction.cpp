// @leetcode id=786 questionId=802 slug=k-th-smallest-prime-fraction lang=cpp site=leetcode.com title="K-th Smallest Prime Fraction"
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        auto cmp = [&](pair<int, int> a, pair<int, int> b) {
            long long val_a = (long long)arr[a.first] * arr[b.second];
            long long val_b = (long long)arr[b.first] * arr[a.second];
            return val_a > val_b;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int j = 1; j < n; j++) {
            pq.push({0, j});
        }

        pair<int, int> result;
        for (int i = 0; i < k; i++) {
            result = pq.top();
            pq.pop();

            int i_idx = result.first;
            int j_idx = result.second;

            if (i_idx + 1 < j_idx) {
                pq.push({i_idx + 1, j_idx});
            }
        }

        return {arr[result.first], arr[result.second]};
    }
};
