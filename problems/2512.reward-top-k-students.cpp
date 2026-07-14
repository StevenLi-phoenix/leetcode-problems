// @leetcode id=2512 questionId=2603 slug=reward-top-k-students lang=cpp site=leetcode.com title="Reward Top K Students"
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());

        int n = report.size();
        vector<pair<int, int>> scores(n); // {score, student_id}
        for (int i = 0; i < n; i++) {
            istringstream iss(report[i]);
            string word;
            int score = 0;
            while (iss >> word) {
                if (pos.count(word)) score += 3;
                else if (neg.count(word)) score -= 1;
            }
            scores[i] = {score, student_id[i]};
        }

        sort(scores.begin(), scores.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(scores[i].second);
        return ans;
    }
};
