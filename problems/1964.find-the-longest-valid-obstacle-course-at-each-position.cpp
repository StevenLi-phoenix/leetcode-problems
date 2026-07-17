// @leetcode id=1964 questionId=2096 slug=find-the-longest-valid-obstacle-course-at-each-position lang=cpp site=leetcode.com title="Find the Longest Valid Obstacle Course at Each Position"
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> tails;
        vector<int> answer(obstacles.size());

        for (size_t i = 0; i < obstacles.size(); i++) {
            int h = obstacles[i];
            auto it = upper_bound(tails.begin(), tails.end(), h);
            if (it == tails.end()) {
                tails.push_back(h);
                answer[i] = tails.size();
            } else {
                *it = h;
                answer[i] = (it - tails.begin()) + 1;
            }
        }

        return answer;
    }
};
