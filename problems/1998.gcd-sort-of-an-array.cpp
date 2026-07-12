// @leetcode id=1998 questionId=2125 slug=gcd-sort-of-an-array lang=cpp site=leetcode.com title="GCD Sort of an Array"
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> spf(maxVal + 1);
        for (int i = 2; i <= maxVal; i++) {
            if (spf[i] == 0)
                for (int j = i; j <= maxVal; j += i)
                    if (spf[j] == 0) spf[j] = i;
        }

        vector<int> parent(maxVal + 1);
        for (int i = 0; i <= maxVal; i++) parent[i] = i;
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a != b) parent[a] = b;
        };

        // Union each number with every prime factor node; numbers sharing a
        // prime factor (directly or transitively) end up in the same set.
        for (int x : nums) {
            int v = x;
            while (v > 1) {
                int p = spf[v];
                unite(x, p);
                while (v % p == 0) v /= p;
            }
        }

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < (int)nums.size(); i++)
            if (find(nums[i]) != find(sorted[i])) return false;
        return true;
    }
};
