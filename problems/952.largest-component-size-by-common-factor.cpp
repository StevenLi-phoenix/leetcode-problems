// @leetcode id=952 questionId=989 slug=largest-component-size-by-common-factor lang=cpp site=leetcode.com title="Largest Component Size by Common Factor"
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> spf(maxVal + 1, 0);
        for (int i = 2; i <= maxVal; ++i) {
            if (spf[i] == 0) {
                for (int j = i; j <= maxVal; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        vector<int> parent(n + maxVal + 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (v > 1) {
                int p = spf[v];
                unite(i, n + p);
                while (v % p == 0) v /= p;
            }
        }

        unordered_map<int, int> sizeByRoot;
        int best = 1;
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            int sz = ++sizeByRoot[r];
            best = max(best, sz);
        }
        return best;
    }
};
