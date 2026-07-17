// @leetcode id=3273 questionId=3531 slug=minimum-amount-of-damage-dealt-to-bob lang=cpp site=leetcode.com title="Minimum Amount of Damage Dealt to Bob"
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<long long> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = (health[i] + power - 1) / power;
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return t[a] * damage[b] < t[b] * damage[a];
        });

        long long total = 0, cumTime = 0;
        for (int i : order) {
            cumTime += t[i];
            total += cumTime * damage[i];
        }

        return total;
    }
};
