// @leetcode id=3378 questionId=3680 slug=count-connected-components-in-lcm-graph lang=cpp site=leetcode.com title="Count Connected Components in LCM Graph"
class Solution {
public:
    vector<int> parent, rnk;
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rnk[px] < rnk[py]) swap(px, py);
        parent[py] = px;
        if (rnk[px] == rnk[py]) rnk[px]++;
    }
    
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        parent.resize(n);
        rnk.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        // Map value -> index
        unordered_map<int, int> valToIdx;
        for (int i = 0; i < n; i++) valToIdx[nums[i]] = i;
        
        // For each m from 1 to threshold, track first nums-value dividing m
        // (as nums index). When we find another, union them.
        // Approach: for each x in nums (x <= threshold), iterate multiples of x up to threshold
        // For each multiple m, connect x with the "representative" of m
        
        vector<int> rep(threshold + 1, -1); // rep[m] = index of first nums-val dividing m
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x > threshold) continue;
            // Iterate over all multiples of x up to threshold
            for (int m = x; m <= threshold; m += x) {
                if (rep[m] == -1) {
                    rep[m] = i;
                } else {
                    unite(rep[m], i);
                }
            }
        }
        
        // Count distinct components
        unordered_set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(find(i));
        }
        return components.size();
    }
};
