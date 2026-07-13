// @leetcode id=587 questionId=587 slug=erect-the-fence lang=cpp site=leetcode.com title="Erect the Fence"
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) return trees; // every point is trivially on the perimeter

        sort(trees.begin(), trees.end());

        auto cross = [](const vector<int>& o, const vector<int>& a, const vector<int>& b) {
            return (long long)(a[0] - o[0]) * (b[1] - o[1]) - (long long)(a[1] - o[1]) * (b[0] - o[0]);
        };

        // Monotone chain, popping only on a strict right turn (cross < 0)
        // so collinear boundary points are kept, not just hull corners.
        vector<vector<int>> lower;
        for (auto& p : trees) {
            while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower.back(), p) < 0)
                lower.pop_back();
            lower.push_back(p);
        }

        vector<vector<int>> upper;
        for (int i = n - 1; i >= 0; i--) {
            auto& p = trees[i];
            while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper.back(), p) < 0)
                upper.pop_back();
            upper.push_back(p);
        }

        set<vector<int>> result(lower.begin(), lower.end());
        result.insert(upper.begin(), upper.end());
        return vector<vector<int>>(result.begin(), result.end());
    }
};
