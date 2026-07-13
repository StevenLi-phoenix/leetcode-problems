// @leetcode id=954 questionId=991 slug=array-of-doubled-pairs lang=cpp site=leetcode.com title="Array of Doubled Pairs"
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        // Process values in order of increasing absolute value: the
        // smallest-magnitude remaining value can only ever be the "x" half
        // of a pair (never "2x"), since anything smaller in magnitude has
        // already been consumed, so greedily pair it with its double.
        unordered_map<int, int> count;
        for (int v : arr) count[v]++;

        vector<int> keys;
        for (auto& [v, c] : count) keys.push_back(v);
        sort(keys.begin(), keys.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : keys) {
            if (count[x] == 0) continue;
            if (x == 0) {
                if (count[x] % 2 != 0) return false;
                count[x] = 0;
                continue;
            }
            int need = 2 * x;
            if (count[need] < count[x]) return false;
            count[need] -= count[x];
            count[x] = 0;
        }
        return true;
    }
};
