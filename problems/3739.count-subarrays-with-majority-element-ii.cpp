// @leetcode id=3739 questionId=4075 slug=count-subarrays-with-majority-element-ii lang=cpp site=leetcode.com title="Count Subarrays With Majority Element II"
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // Build prefix sum array: +1 if nums[i]==target, -1 otherwise
        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }
        
        // Coordinate compress pref values
        vector<int> sorted_pref = pref;
        sort(sorted_pref.begin(), sorted_pref.end());
        sorted_pref.erase(unique(sorted_pref.begin(), sorted_pref.end()), sorted_pref.end());
        int m = sorted_pref.size();
        
        // Map pref values to 1-indexed positions
        auto getIdx = [&](int val) {
            return (int)(lower_bound(sorted_pref.begin(), sorted_pref.end(), val) - sorted_pref.begin()) + 1;
        };
        
        // Fenwick Tree (BIT) for prefix sum queries
        vector<int> bit(m + 2, 0);
        auto update = [&](int i) {
            for (; i <= m; i += i & (-i))
                bit[i]++;
        };
        auto query = [&](int i) -> long long {
            long long s = 0;
            for (; i > 0; i -= i & (-i))
                s += bit[i];
            return s;
        };
        
        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            int idx = getIdx(pref[k]);
            // Count how many previous pref values are strictly less than pref[k]
            // i.e., those with compressed index < idx
            if (idx > 1) ans += query(idx - 1);
            update(idx);
        }
        
        return ans;
    }
};
