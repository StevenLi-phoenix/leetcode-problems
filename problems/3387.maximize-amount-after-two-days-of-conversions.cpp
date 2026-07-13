// @leetcode id=3387 questionId=3613 slug=maximize-amount-after-two-days-of-conversions lang=cpp site=leetcode.com title="Maximize Amount After Two Days of Conversions"
class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        // Each day's graph is a forest (no cycles/contradictions), so a
        // single DFS from initialCurrency gives the unique best rate to
        // every reachable currency. Day 2 can be inverted (currency back
        // to initial), so combine both maps over every currency reachable
        // on day 1.
        auto buildRates = [&](vector<vector<string>>& pairs, vector<double>& rates) {
            unordered_map<string, vector<pair<string, double>>> adj;
            for (size_t i = 0; i < pairs.size(); i++) {
                adj[pairs[i][0]].push_back({pairs[i][1], rates[i]});
                adj[pairs[i][1]].push_back({pairs[i][0], 1.0 / rates[i]});
            }

            unordered_map<string, double> best;
            best[initialCurrency] = 1.0;
            vector<string> stack = {initialCurrency};
            while (!stack.empty()) {
                string cur = stack.back();
                stack.pop_back();
                for (auto& [next, rate] : adj[cur]) {
                    if (best.find(next) == best.end()) {
                        best[next] = best[cur] * rate;
                        stack.push_back(next);
                    }
                }
            }
            return best;
        };

        unordered_map<string, double> day1 = buildRates(pairs1, rates1);
        unordered_map<string, double> day2 = buildRates(pairs2, rates2);

        double ans = 1.0;
        for (auto& [currency, rate1] : day1) {
            auto it = day2.find(currency);
            if (it != day2.end()) {
                ans = max(ans, rate1 / it->second);
            }
        }
        return ans;
    }
};
