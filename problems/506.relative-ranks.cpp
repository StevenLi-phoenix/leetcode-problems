// @leetcode id=506 questionId=506 slug=relative-ranks lang=cpp site=leetcode.com title="Relative Ranks"
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return score[a] > score[b]; });

        vector<string> answer(n);
        for (int rank = 0; rank < n; rank++) {
            int i = idx[rank];
            if (rank == 0) answer[i] = "Gold Medal";
            else if (rank == 1) answer[i] = "Silver Medal";
            else if (rank == 2) answer[i] = "Bronze Medal";
            else answer[i] = to_string(rank + 1);
        }
        return answer;
    }
};
