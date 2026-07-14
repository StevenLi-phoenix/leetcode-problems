// @leetcode id=1899 questionId=2026 slug=merge-triplets-to-form-target-triplet lang=cpp site=leetcode.com title="Merge Triplets to Form Target Triplet"
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int best0 = 0, best1 = 0, best2 = 0;
        for (auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            best0 = max(best0, t[0]);
            best1 = max(best1, t[1]);
            best2 = max(best2, t[2]);
        }
        return best0 == target[0] && best1 == target[1] && best2 == target[2];
    }
};
