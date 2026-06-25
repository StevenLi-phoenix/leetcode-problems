// @leetcode id=2246 questionId=2364 slug=longest-path-with-different-adjacent-characters lang=cpp site=leetcode.com title="Longest Path With Different Adjacent Characters"
class Solution {
public:
    int ans = 1;
    
    // Returns the longest path starting at node going down
    int dfs(int node, vector<vector<int>>& children, const string& s) {
        int top1 = 0, top2 = 0; // two longest arms from children
        
        for (int child : children[node]) {
            int childLen = dfs(child, children, s);
            if (s[child] == s[node]) continue; // can't extend
            
            if (childLen >= top1) {
                top2 = top1;
                top1 = childLen;
            } else if (childLen > top2) {
                top2 = childLen;
            }
        }
        
        // Path through this node: top1 + top2 + 1
        ans = max(ans, top1 + top2 + 1);
        
        return top1 + 1; // longest path starting at this node
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        
        ans = 1;
        dfs(0, children, s);
        return ans;
    }
};
