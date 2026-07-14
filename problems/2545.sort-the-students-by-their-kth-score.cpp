// @leetcode id=2545 questionId=2631 slug=sort-the-students-by-their-kth-score lang=cpp site=leetcode.com title="Sort the Students by Their Kth Score"
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](const vector<int>& a, const vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};
