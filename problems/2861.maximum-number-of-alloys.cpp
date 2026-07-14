// @leetcode id=2861 questionId=3095 slug=maximum-number-of-alloys lang=cpp site=leetcode.com title="Maximum Number of Alloys"
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        auto feasible = [&](vector<int>& comp, long long amount) -> bool {
            long long total = 0;
            for (int j = 0; j < n; j++) {
                long long need = (long long)comp[j] * amount - stock[j];
                if (need > 0) total += need * cost[j];
                if (total > budget) return false;
            }
            return total <= budget;
        };

        long long ans = 0;
        for (auto& comp : composition) {
            long long lo = 0, hi = 2000000000LL;
            while (lo < hi) {
                long long mid = lo + (hi - lo + 1) / 2;
                if (feasible(comp, mid)) lo = mid;
                else hi = mid - 1;
            }
            ans = max(ans, lo);
        }
        return (int)ans;
    }
};
