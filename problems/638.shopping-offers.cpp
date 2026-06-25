// @leetcode id=638 questionId=638 slug=shopping-offers lang=cpp site=leetcode.com title="Shopping Offers"
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> memo;
        function<int(vector<int>)> dfs = [&](vector<int> cur) -> int {
            auto it = memo.find(cur);
            if (it != memo.end()) return it->second;
            int n = price.size();
            int best = 0;
            for (int i = 0; i < n; i++) best += cur[i] * price[i];
            for (auto& off : special) {
                vector<int> next(n);
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    next[i] = cur[i] - off[i];
                    if (next[i] < 0) { ok = false; break; }
                }
                if (!ok) continue;
                best = min(best, off[n] + dfs(next));
            }
            memo[cur] = best;
            return best;
        };
        return dfs(needs);
    }
};
