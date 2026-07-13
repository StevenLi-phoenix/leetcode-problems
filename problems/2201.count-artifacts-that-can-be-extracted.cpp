// @leetcode id=2201 questionId=1312 slug=count-artifacts-that-can-be-extracted lang=cpp site=leetcode.com title="Count Artifacts That Can Be Extracted"
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int m = artifacts.size();
        unordered_map<int, int> cellToArtifact; // encoded (r,c) -> artifact index
        vector<int> remaining(m);
        for (int i = 0; i < m; i++) {
            auto& a = artifacts[i];
            for (int r = a[0]; r <= a[2]; r++)
                for (int c = a[1]; c <= a[3]; c++) {
                    cellToArtifact[r * n + c] = i;
                    remaining[i]++;
                }
        }

        for (auto& d : dig) {
            int key = d[0] * n + d[1];
            auto it = cellToArtifact.find(key);
            if (it != cellToArtifact.end()) remaining[it->second]--;
        }

        int count = 0;
        for (int r : remaining) if (r == 0) count++;
        return count;
    }
};
