// @leetcode id=3362 questionId=3647 slug=zero-array-transformation-iii lang=cpp site=leetcode.com title="Zero Array Transformation III"
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(queries.begin(), queries.end());

        priority_queue<int> heap; // max-heap of r values (by end index)
        vector<int> expire(n + 1, 0);
        long long curActive = 0;
        int selected = 0;
        int idx = 0;
        int q = queries.size();

        for (int i = 0; i < n; i++) {
            curActive -= expire[i];

            while (idx < q && queries[idx][0] == i) {
                heap.push(queries[idx][1]);
                idx++;
            }

            long long needed = nums[i] - curActive;
            while (needed > 0 && !heap.empty()) {
                int r = heap.top();
                heap.pop();
                if (r < i) continue;
                selected++;
                curActive++;
                expire[r + 1]++;
                needed--;
            }
            if (needed > 0) return -1;
        }
        return q - selected;
    }
};
