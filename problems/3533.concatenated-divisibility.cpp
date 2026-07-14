// @leetcode id=3533 questionId=3841 slug=concatenated-divisibility lang=cpp site=leetcode.com title="Concatenated Divisibility"
class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p10(n); // 10^(digit length of nums[i]) mod k
        for (int i = 0; i < n; i++) {
            int len = to_string(nums[i]).length();
            long long p = 1;
            for (int d = 0; d < len; d++) p = p * 10 % k;
            p10[i] = (int)p;
        }

        int fullMask = 1 << n;
        // complete[mask][rem] = can the remaining indices in `mask`, appended
        // in some order starting from remainder `rem`, reach remainder 0.
        vector<vector<char>> complete(fullMask, vector<char>(k, -1));
        complete[0][0] = 1;

        function<bool(int, int)> canComplete = [&](int mask, int rem) -> bool {
            if (complete[mask][rem] != -1) return complete[mask][rem];
            complete[mask][rem] = 0; // guard against reuse during computation (DAG, no cycles since mask shrinks)
            bool ok = false;
            for (int i = 0; i < n && !ok; i++) {
                if (!(mask & (1 << i))) continue;
                int newRem = (int)(((long long)rem * p10[i] + nums[i]) % k);
                if (canComplete(mask ^ (1 << i), newRem)) ok = true;
            }
            complete[mask][rem] = ok ? 1 : 0;
            return ok;
        };

        if (!canComplete(fullMask - 1, 0)) return {};

        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b) { return nums[a] < nums[b]; });

        vector<int> result;
        int mask = fullMask - 1, rem = 0;
        for (int step = 0; step < n; step++) {
            for (int idx : order) {
                if (!(mask & (1 << idx))) continue;
                int newRem = (int)(((long long)rem * p10[idx] + nums[idx]) % k);
                if (canComplete(mask ^ (1 << idx), newRem)) {
                    result.push_back(nums[idx]);
                    mask ^= (1 << idx);
                    rem = newRem;
                    break;
                }
            }
        }
        return result;
    }
};
