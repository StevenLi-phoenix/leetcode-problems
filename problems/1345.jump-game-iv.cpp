// @leetcode id=1345 questionId=1447 slug=jump-game-iv lang=cpp site=leetcode.com title="Jump Game IV"
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        // Build map from value to list of indices
        unordered_map<int, vector<int>> valToIdx;
        for (int i = 0; i < n; i++) {
            valToIdx[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                int i = q.front(); q.pop();
                
                // Jump to same value indices
                if (valToIdx.count(arr[i])) {
                    for (int j : valToIdx[arr[i]]) {
                        if (j == n - 1) return steps;
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                    // Clear to avoid revisiting
                    valToIdx.erase(arr[i]);
                }
                
                // Jump to i+1
                if (i + 1 < n) {
                    if (i + 1 == n - 1) return steps;
                    if (!visited[i + 1]) {
                        visited[i + 1] = true;
                        q.push(i + 1);
                    }
                }
                
                // Jump to i-1
                if (i - 1 >= 0) {
                    if (i - 1 == n - 1) return steps;
                    if (!visited[i - 1]) {
                        visited[i - 1] = true;
                        q.push(i - 1);
                    }
                }
            }
        }
        
        return -1;
    }
};
