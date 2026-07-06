// @leetcode id=1815 questionId=1924 slug=maximum-number-of-groups-getting-fresh-donuts lang=cpp site=leetcode.com title="Maximum Number of Groups Getting Fresh Donuts"
class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize, 0);
        for (int g : groups) cnt[g % batchSize]++;

        int ans = cnt[0];

        for (int r = 1; r * 2 < batchSize; ++r) {
            int mn = min(cnt[r], cnt[batchSize - r]);
            ans += mn;
            cnt[r] -= mn;
            cnt[batchSize - r] -= mn;
        }
        if (batchSize % 2 == 0) {
            int mid = batchSize / 2;
            ans += cnt[mid] / 2;
            cnt[mid] %= 2;
        }

        unordered_map<long long, int> memo;
        vector<int> rem(cnt.begin() + 1, cnt.end()); // rem[i] = cnt[i+1]
        int m = rem.size();

        auto encode = [&](int leftover, vector<int>& r) {
            long long key = leftover;
            for (int v : r) key = key * 31 + v;
            return key;
        };

        function<int(int)> dfs = [&](int leftover) -> int {
            bool allZero = true;
            for (int v : rem) if (v > 0) { allZero = false; break; }
            if (allZero) return 0;

            long long key = encode(leftover, rem);
            auto it = memo.find(key);
            if (it != memo.end()) return it->second;

            int best = 0;
            for (int i = 0; i < m; ++i) {
                if (rem[i] > 0) {
                    int r = i + 1;
                    rem[i]--;
                    int happy = (leftover == 0) ? 1 : 0;
                    int newLeftover = (leftover + r) % batchSize;
                    best = max(best, happy + dfs(newLeftover));
                    rem[i]++;
                }
            }
            memo[key] = best;
            return best;
        };

        ans += dfs(0);
        return ans;
    }
};
