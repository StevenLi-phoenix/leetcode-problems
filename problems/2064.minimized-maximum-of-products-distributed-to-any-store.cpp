// @leetcode id=2064 questionId=2188 slug=minimized-maximum-of-products-distributed-to-any-store lang=cpp site=leetcode.com title="Minimized Maximum of Products Distributed to Any Store"
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto check = [&](int x) -> bool {
            long long stores = 0;
            for (int q : quantities) {
                stores += (q + x - 1) / x;
            }
            return stores <= n;
        };
        
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end());
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
