// @leetcode id=3399 questionId=3706 slug=smallest-substring-with-identical-characters-ii lang=cpp site=leetcode.com title="Smallest Substring With Identical Characters II"
class Solution {
public:
    int minLength(string s, int numOps) {
        int n = s.size();
        
        auto check = [&](int mid) -> bool {
            int ops = 0;
            if (mid == 1) {
                // Need to alternate: count mismatches vs "0101..." and "1010..."
                int cost0 = 0, cost1 = 0;
                for (int i = 0; i < n; i++) {
                    if (s[i] != (char)('0' + (i % 2))) cost0++;
                    if (s[i] != (char)('0' + ((i + 1) % 2))) cost1++;
                }
                return min(cost0, cost1) <= numOps;
            }
            // For mid >= 2: each run of length L needs floor(L / (mid+1)) flips
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && s[j] == s[i]) j++;
                ops += (j - i) / (mid + 1);
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
