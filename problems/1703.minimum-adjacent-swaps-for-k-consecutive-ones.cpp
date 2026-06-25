// @leetcode id=1703 questionId=1805 slug=minimum-adjacent-swaps-for-k-consecutive-ones lang=cpp site=leetcode.com title="Minimum Adjacent Swaps for K Consecutive Ones"
class Solution {
public:
    long long minMoves(vector<int>& nums, int k) {
        // Collect positions of 1s
        vector<long long> pos;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 1) pos.push_back(i);
        }
        
        int m = pos.size();
        // q[j] = pos[j] - j (adjusted positions)
        vector<long long> q(m);
        for (int i = 0; i < m; i++) {
            q[i] = pos[i] - i;
        }
        
        // Prefix sums of q
        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefix[i + 1] = prefix[i] + q[i];
        }
        
        long long ans = LLONG_MAX;
        
        // Sliding window of size k
        for (int i = 0; i + k - 1 < m; i++) {
            int mid = i + k / 2;
            long long qm = q[mid];
            
            // Cost = sum |q[j] - qm| for j in [i, i+k-1]
            // = sum of (qm - q[j]) for j < mid + sum of (q[j] - qm) for j > mid
            // left part: [i, mid-1]
            long long leftSum = (long long)(mid - i) * qm - (prefix[mid] - prefix[i]);
            // right part: [mid+1, i+k-1]
            long long rightSum = (prefix[i + k] - prefix[mid + 1]) - (long long)(i + k - 1 - mid) * qm;
            
            ans = min(ans, leftSum + rightSum);
        }
        
        return ans;
    }
};
