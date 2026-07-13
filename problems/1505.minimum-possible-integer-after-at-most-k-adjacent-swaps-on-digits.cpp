// @leetcode id=1505 questionId=1629 slug=minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits lang=cpp site=leetcode.com title="Minimum Possible Integer After at Most K Adjacent Swaps On Digits"
class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        vector<deque<int>> positions(10);
        for (int i = 0; i < n; i++) positions[num[i] - '0'].push_back(i);

        // BIT over original positions: 1 = still available (not yet moved
        // to the output). prefixSum(p) = number of available positions at
        // or before p, which equals the adjacent-swap cost to bring the
        // element at p to the current front of the remaining sequence.
        vector<int> bit(n + 1, 0);
        auto update = [&](int i, int delta) {
            for (i++; i <= n; i += i & (-i)) bit[i] += delta;
        };
        auto prefixSum = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & (-i)) res += bit[i];
            return res;
        };
        for (int i = 0; i < n; i++) update(i, 1);

        string result;
        result.reserve(n);
        long long remainingK = k;
        for (int step = 0; step < n; step++) {
            for (int d = 0; d <= 9; d++) {
                if (positions[d].empty()) continue;
                int pos = positions[d].front();
                int cost = prefixSum(pos) - 1; // exclude the element itself
                if (cost <= remainingK) {
                    remainingK -= cost;
                    positions[d].pop_front();
                    update(pos, -1);
                    result += ('0' + d);
                    break;
                }
            }
        }
        return result;
    }
};
