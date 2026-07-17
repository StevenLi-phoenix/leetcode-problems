// @leetcode id=630 questionId=630 slug=course-schedule-iii lang=cpp site=leetcode.com title="Course Schedule III"
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap;
        long long curTime = 0;

        for (auto& c : courses) {
            int duration = c[0], lastDay = c[1];
            curTime += duration;
            maxHeap.push(duration);
            if (curTime > lastDay) {
                curTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};
