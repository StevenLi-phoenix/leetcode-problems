// @leetcode id=1900 questionId=2028 slug=the-earliest-and-latest-rounds-where-players-compete lang=cpp site=leetcode.com title="The Earliest and Latest Rounds Where Players Compete"
class Solution {
public:
    map<tuple<int,int,int>, pair<int,int>> memo;

    pair<int,int> solve(int n, int a, int b) {
        if (a > b) swap(a, b);
        if (a + b == n + 1) return {1, 1};

        auto key = make_tuple(n, a, b);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int pa = min(a, n + 1 - a);
        int pb = min(b, n + 1 - b);

        vector<int> otherPairs;
        for (int i = 1; i <= n / 2; i++) {
            if (i != pa && i != pb) otherPairs.push_back(i);
        }
        int k = otherPairs.size();

        int mn = INT_MAX, mx = INT_MIN;

        for (int mask = 0; mask < (1 << k); mask++) {
            vector<int> survivors;
            survivors.push_back(a);
            survivors.push_back(b);
            if (n % 2 == 1) {
                int mid = (n + 1) / 2;
                if (mid != a && mid != b) survivors.push_back(mid);
            }
            for (int j = 0; j < k; j++) {
                int i = otherPairs[j];
                if (mask & (1 << j)) survivors.push_back(i);
                else survivors.push_back(n + 1 - i);
            }
            sort(survivors.begin(), survivors.end());

            int newN = survivors.size();
            int ra = -1, rb = -1;
            for (int idx = 0; idx < newN; idx++) {
                if (survivors[idx] == a) ra = idx + 1;
                if (survivors[idx] == b) rb = idx + 1;
            }

            auto res = solve(newN, ra, rb);
            mn = min(mn, res.first + 1);
            mx = max(mx, res.second + 1);
        }

        pair<int,int> result = {mn, mx};
        memo[key] = result;
        return result;
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto res = solve(n, firstPlayer, secondPlayer);
        return {res.first, res.second};
    }
};
