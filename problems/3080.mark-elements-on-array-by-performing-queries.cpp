// @leetcode id=3080 questionId=3306 slug=mark-elements-on-array-by-performing-queries lang=cpp site=leetcode.com title="Mark Elements on Array by Performing Queries"
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> marked(n, false);
        long long sum = 0;
        for (int x : nums) sum += x;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});

        vector<long long> result;
        result.reserve(queries.size());

        for (auto& q : queries) {
            int idx = q[0], k = q[1];
            if (!marked[idx]) {
                marked[idx] = true;
                sum -= nums[idx];
            }
            while (k > 0 && !pq.empty()) {
                auto [val, i] = pq.top();
                if (marked[i]) {
                    pq.pop();
                    continue;
                }
                pq.pop();
                marked[i] = true;
                sum -= val;
                k--;
            }
            result.push_back(sum);
        }
        return result;
    }
};
