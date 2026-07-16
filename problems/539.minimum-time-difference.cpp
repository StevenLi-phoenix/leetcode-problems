// @leetcode id=539 questionId=539 slug=minimum-time-difference lang=cpp site=leetcode.com title="Minimum Time Difference"
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (auto& t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        sort(minutes.begin(), minutes.end());

        int best = INT_MAX;
        int n = minutes.size();
        for (int i = 1; i < n; i++) {
            best = min(best, minutes[i] - minutes[i - 1]);
        }
        best = min(best, 1440 - minutes[n - 1] + minutes[0]);
        return best;
    }
};
