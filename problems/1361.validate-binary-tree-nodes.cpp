// @leetcode id=1361 questionId=1275 slug=validate-binary-tree-nodes lang=cpp site=leetcode.com title="Validate Binary Tree Nodes"
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (++indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                if (++indegree[rightChild[i]] > 1) return false;
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;
        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;
            if (leftChild[node] != -1) {
                if (visited[leftChild[node]]) return false;
                visited[leftChild[node]] = true;
                q.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                if (visited[rightChild[node]]) return false;
                visited[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }
        return count == n;
    }
};
