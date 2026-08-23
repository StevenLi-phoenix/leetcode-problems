// @leetcode id=2492 questionId=2582 slug=minimum-score-of-a-path-between-two-cities lang=cpp site=leetcode.com title="Minimum Score of a Path Between Two Cities"
class Solution {
public:
    vector<int> parent, rnk;
    int find(int x){ return parent[x]==x ? x : parent[x]=find(parent[x]); }
    void unite(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(rnk[a] < rnk[b]) swap(a,b);
        parent[b] = a;
        if(rnk[a] == rnk[b]) rnk[a]++;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        rnk.assign(n+1, 0);
        for(int i = 0; i <= n; i++) parent[i] = i;
        for(auto& r : roads) unite(r[0], r[1]);
        int root = find(1);
        int ans = INT_MAX;
        for(auto& r : roads){
            if(find(r[0]) == root){
                ans = min(ans, r[2]);
            }
        }
        return ans;
    }
};
