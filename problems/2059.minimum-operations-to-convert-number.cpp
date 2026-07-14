// @leetcode id=2059 questionId=2183 slug=minimum-operations-to-convert-number lang=cpp site=leetcode.com title="Minimum Operations to Convert Number"
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if (start == goal) return 0;
        vector<bool> visited(1001, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                int x = q.front();
                q.pop();
                for (int n : nums) {
                    int candidates[3] = {x + n, x - n, x ^ n};
                    for (int y : candidates) {
                        if (y == goal) return steps;
                        if (y >= 0 && y <= 1000 && !visited[y]) {
                            visited[y] = true;
                            q.push(y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
