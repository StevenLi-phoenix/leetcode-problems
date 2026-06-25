// @leetcode id=3398 questionId=3690 slug=smallest-substring-with-identical-characters-i lang=cpp site=leetcode.com title="Smallest Substring With Identical Characters I"
class Solution {
public:
    int minLength(string s, int numOps) {
        int n = s.size();
        
        // Binary search on the answer
        // Check if we can achieve max identical substring length <= mid
        auto check = [&](int mid) -> bool {
            if (mid == 1) {
                // String must be alternating
                // Count mismatches with "010101..." and "101010..."
                int cnt0 = 0, cnt1 = 0;
                for (int i = 0; i < n; i++) {
                    if (s[i] - '0' != i % 2) cnt0++;
                    if (s[i] - '0' != (i+1) % 2) cnt1++;
                }
                return min(cnt0, cnt1) <= numOps;
            }
            // For mid >= 2: greedily flip within each run
            int ops = 0;
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && s[j] == s[i]) j++;
                int len = j - i;
                // Need to break this run of len into pieces of at most mid
                // Place a flip every mid+1 chars: need floor(len / (mid+1)) flips
                ops += len / (mid + 1);
                i = j;
            }
            return ops <= numOps;
        };
        
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
