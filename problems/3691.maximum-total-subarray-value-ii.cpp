// @leetcode id=3691 questionId=4007 slug=maximum-total-subarray-value-ii lang=cpp site=leetcode.com title="Maximum Total Subarray Value II"
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        // For each index i, consider subarrays where nums[i] is the max.
        // The best such subarray has min as small as possible.
        // Use monotonic stack to find, for each element as max, 
        // the best min in its "dominance range".
        
        // We use a max-heap of (value, maxIdx, minIdx, direction)
        // where direction indicates how to expand the search.
        // This is the standard "lazy heap" approach for this type of problem.
        
        // Alternative simpler O(n log n) approach:
        // Observation: optimal subarrays are contiguous, and we can use
        // the fact that the multiset of all subarray max-min values can be
        // efficiently enumerated using a heap + two pointers.
        
        // Simplest correct approach for contest:
        // Use sorted pairs: for each pair of indices (i,j), value = |nums[i]-nums[j]|
        // but constrained to be a valid subarray (i<=j or j<=i doesn't matter, 
        // just need i and j to be in same subarray where one is max and other is min).
        // The key: any two elements can form a subarray where they are max and min
        // IF there's no element outside [min,max] range between them... actually
        // they CAN always form a valid subarray (just take subarray from min(i,j) to max(i,j)).
        // The max of that subarray >= nums[i] or nums[j] (the larger one), 
        // and min <= the smaller one. So actual value >= |nums[i]-nums[j]|.
        // But we want EXACTLY max-min, so we need the subarray's max to be the larger
        // and min to be the smaller.
        
        // The correct greedy: use a max-heap initialized with all adjacent pairs' differences.
        // When we pop (diff, l, r), we add the pair (l-1, r) and (l, r+1) if not already done.
        // This enumerates all subarrays by their max-min in decreasing order.
        
        // Actually the cleanest approach: 
        // Enumerate using Cartesian tree / segment tree based heap.
        // For this problem size, use priority_queue with (maxval-minval, l, r, maxpos, minpos).
        
        // Let's use the simpler O(n^2) for small n, but n can be 5*10^4 so we need better.
        // Use the "two monotonic stacks" approach to get all (max,min) candidates.
        
        // PRACTICAL SOLUTION: 
        // For each element, find the nearest greater/smaller using monotonic stacks,
        // generate candidate pairs, put in max-heap, greedily pick top k.
        
        // Actually the cleanest known solution uses segment tree to maintain
        // for each position i the best subarray starting at i.
        
        // Let me use the heap-expansion approach:
        // Start with all subarrays of length 1 (value=0), but that's inefficient.
        // Better: start with all adjacent pairs.
        
        // KNOWN SOLUTION PATTERN for "top-k subarray max-min":
        // Use a max-heap. Initialize with the subarray [0..n-1] (or all length-2 subarrays).
        // When pop [l,r], push [l+1,r] and [l,r-1] if l+1<=r and l<=r-1.
        // But this gives O(k log k) but generates duplicates.
        
        // Use visited set to avoid duplicates.
        // With k up to 1e5 and n up to 5e4, this should work.
        
        // Precompute sparse table for O(1) range max/min queries.
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        
        vector<vector<int>> maxT(LOG, vector<int>(n)), minT(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) maxT[0][i] = minT[0][i] = nums[i];
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1<<j) <= n; i++) {
                maxT[j][i] = max(maxT[j-1][i], maxT[j-1][i+(1<<(j-1))]);
                minT[j][i] = min(minT[j-1][i], minT[j-1][i+(1<<(j-1))]);
            }
        }
        auto qmax = [&](int l, int r) {
            int k = __lg(r-l+1);
            return max(maxT[k][l], maxT[k][r-(1<<k)+1]);
        };
        auto qmin = [&](int l, int r) {
            int k = __lg(r-l+1);
            return min(minT[k][l], minT[k][r-(1<<k)+1]);
        };
        
        // Max-heap: (value, l, r)
        using T = tuple<long long,int,int>;
        priority_queue<T> pq;
        set<pair<int,int>> visited;
        
        auto push = [&](int l, int r) {
            if (l > r || l < 0 || r >= n) return;
            if (visited.count({l,r})) return;
            visited.insert({l,r});
            long long val = qmax(l,r) - qmin(l,r);
            pq.push({val, l, r});
        };
        
        // Initialize with all single elements expanded - just push [0, n-1] and expand
        // Actually better: push all adjacent pairs to seed the heap
        for (int i = 0; i+1 < n; i++) push(i, i+1);
        push(0, n-1);
        
        long long ans = 0;
        int cnt = 0;
        while (!pq.empty() && cnt < k) {
            auto [val, l, r] = pq.top(); pq.pop();
            ans += val;
            cnt++;
            push(l-1, r);
            push(l, r+1);
            push(l+1, r);
            push(l, r-1);
        }
        return ans;
    }
};
