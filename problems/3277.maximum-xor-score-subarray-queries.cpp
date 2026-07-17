// @leetcode id=3277 questionId=3551 slug=maximum-xor-score-subarray-queries lang=cpp site=leetcode.com title="Maximum XOR Score Subarray Queries"
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> score(n, vector<int>(n, 0));
        vector<vector<int>> best(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            score[i][i] = nums[i];
            best[i][i] = nums[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                score[i][j] = score[i][j - 1] ^ score[i + 1][j];
                best[i][j] = max({best[i][j - 1], best[i + 1][j], score[i][j]});
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());
        for (auto& q : queries) {
            answer.push_back(best[q[0]][q[1]]);
        }

        return answer;
    }
};
