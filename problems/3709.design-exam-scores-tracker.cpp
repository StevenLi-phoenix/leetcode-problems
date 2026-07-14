// @leetcode id=3709 questionId=4059 slug=design-exam-scores-tracker lang=cpp site=leetcode.com title="Design Exam Scores Tracker"
class ExamTracker {
public:
    vector<int> times;
    vector<long long> prefix;

    ExamTracker() {
        prefix.push_back(0);
    }

    void record(int time, int score) {
        times.push_back(time);
        prefix.push_back(prefix.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        int lo = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int hi = upper_bound(times.begin(), times.end(), endTime) - times.begin();
        if (lo >= hi) return 0;
        return prefix[hi] - prefix[lo];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
