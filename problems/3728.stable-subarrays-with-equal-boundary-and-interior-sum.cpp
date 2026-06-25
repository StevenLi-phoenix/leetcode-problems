// @leetcode id=3728 questionId=4083 slug=stable-subarrays-with-equal-boundary-and-interior-sum lang=cpp site=leetcode.com title="Stable Subarrays With Equal Boundary and Interior Sum"
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> p(n);
        p[0] = capacity[0];
        for (int i = 1; i < n; i++) p[i] = p[i-1] + capacity[i];
        
        // For stable [l, r]: capacity[l] == capacity[r] and p[r-1] - p[l] == capacity[r]
        // => p[l] = p[r-1] - capacity[r], and r >= l+2
        
        // We iterate r from 0 to n-1
        // We maintain freq of (capacity[l], p[l]) for l <= r-2
        map<pair<int,long long>, long long> freq;
        long long ans = 0;
        
        for (int r = 0; r < n; r++) {
            // Add l = r-2 to freq (so l <= r-2 is covered)
            if (r >= 2) {
                int l = r - 2;
                freq[{capacity[l], p[l]}]++;
            }
            // Count valid l for this r
            if (r >= 2) {
                long long need_p = p[r-1] - (long long)capacity[r];
                auto key = make_pair(capacity[r], need_p);
                auto it = freq.find(key);
                if (it != freq.end()) {
                    ans += it->second;
                }
            }
        }
        
        return ans;
    }
};
