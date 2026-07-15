// @leetcode id=2593 questionId=2695 slug=find-score-of-an-array-after-marking-all-elements lang=cpp site=leetcode.com title="Find Score of an Array After Marking All Elements"
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < n; i++) minHeap.push({nums[i], i});

        long long score = 0;
        while (!minHeap.empty()) {
            auto [val, idx] = minHeap.top();
            minHeap.pop();
            if (marked[idx]) continue;
            score += val;
            marked[idx] = true;
            if (idx - 1 >= 0) marked[idx - 1] = true;
            if (idx + 1 < n) marked[idx + 1] = true;
        }
        return score;
    }
};
