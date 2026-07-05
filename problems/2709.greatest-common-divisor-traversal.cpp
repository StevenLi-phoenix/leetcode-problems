// @leetcode id=2709 questionId=2827 slug=greatest-common-divisor-traversal lang=cpp site=leetcode.com title="Greatest Common Divisor Traversal"
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> spf(maxVal + 1);
        for (int i = 2; i <= maxVal; ++i) {
            if (spf[i] == 0) {
                for (int j = i; j <= maxVal; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        unordered_map<int, int> primeNode;
        vector<int> parent;
        auto newNode = [&]() { parent.push_back(parent.size()); return (int)parent.size() - 1; };
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        for (int i = 0; i < n; ++i) newNode(); // index nodes 0..n-1

        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (v > 1) {
                int p = spf[v];
                if (!primeNode.count(p)) primeNode[p] = newNode();
                unite(i, primeNode[p]);
                while (v % p == 0) v /= p;
            }
        }

        int root = find(0);
        for (int i = 1; i < n; ++i) {
            if (find(i) != root) return false;
        }
        return true;
    }
};
