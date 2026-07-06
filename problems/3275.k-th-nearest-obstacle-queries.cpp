// @leetcode id=3275 questionId=3495 slug=k-th-nearest-obstacle-queries lang=cpp site=leetcode.com title="K-th Nearest Obstacle Queries"
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<long long> maxHeap; // keeps the k smallest distances seen so far
        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            long long dist = llabs((long long)q[0]) + llabs((long long)q[1]);
            maxHeap.push(dist);
            if ((int)maxHeap.size() > k) maxHeap.pop();

            if ((int)maxHeap.size() < k) ans.push_back(-1);
            else ans.push_back((int)maxHeap.top());
        }
        return ans;
    }
};
