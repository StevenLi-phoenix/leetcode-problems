// @leetcode id=3356 questionId=3643 slug=zero-array-transformation-ii lang=cpp site=leetcode.com title="Zero Array Transformation II"
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        
        // Check if using first k queries, nums can become zero array
        auto canZero = [&](int k) -> bool {
            vector<long long> diff(n + 1, 0);
            for (int i = 0; i < k; i++) {
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                diff[l] += val;
                diff[r + 1] -= val;
            }
            long long running = 0;
            for (int i = 0; i < n; i++) {
                running += diff[i];
                if (running < nums[i]) return false;
            }
            return true;
        };
        
        if (canZero(0)) return 0;
        if (!canZero(q)) return -1;
        
        // Binary search for minimum k
        int lo = 1, hi = q;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (canZero(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
