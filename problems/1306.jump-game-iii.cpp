// @leetcode id=1306 questionId=1428 slug=jump-game-iii lang=cpp site=leetcode.com title="Jump Game III"
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (arr[cur] == 0) return true;
            int next1 = cur + arr[cur];
            int next2 = cur - arr[cur];
            if (next1 < n && !visited[next1]) {
                visited[next1] = true;
                q.push(next1);
            }
            if (next2 >= 0 && !visited[next2]) {
                visited[next2] = true;
                q.push(next2);
            }
        }
        return false;
    }
};
