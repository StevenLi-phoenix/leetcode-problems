// @leetcode id=3942 questionId=4184 slug=minimum-operations-to-sort-a-permutation lang=cpp site=leetcode.com title="Minimum Operations to Sort a Permutation"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Reachable states under {reverse, rotate-left-by-1} are exactly the
        // n rotations of nums and the n rotations of reverse(nums) (a
        // dihedral group of order 2n). Using the relation F R F = R^{-1},
        // a pure rotation by k costs min(k, n-k+2); a "reversed" rotation by
        // k costs min(k, n-k) + 1 (reverse+rotate, or rotate+reverse).
        int n = nums.size();

        auto tryRotation = [&](const vector<int>& arr) -> int {
            int pos0 = -1;
            for (int i = 0; i < n; i++)
                if (arr[i] == 0) { pos0 = i; break; }
            for (int i = 0; i < n; i++)
                if (arr[(pos0 + i) % n] != i) return -1;
            return pos0;
        };

        int best = INT_MAX;

        int k1 = tryRotation(nums);
        if (k1 != -1) best = min(best, min(k1, n - k1 + 2));

        vector<int> rev(nums.rbegin(), nums.rend());
        int k2 = tryRotation(rev);
        if (k2 != -1) best = min(best, min(k2, n - k2) + 1);

        return best == INT_MAX ? -1 : best;
    }
};
