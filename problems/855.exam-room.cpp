// @leetcode id=855 questionId=885 slug=exam-room lang=cpp site=leetcode.com title="Exam Room"
class ExamRoom {
private:
    int n;
    set<int> occupied;

public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if (occupied.empty()) {
            occupied.insert(0);
            return 0;
        }

        int bestSeat = 0;
        int bestDist = -1;

        int first = *occupied.begin();
        if (first > bestDist) {
            bestDist = first;
            bestSeat = 0;
        }

        int prev = -1;
        for (int cur : occupied) {
            if (prev != -1) {
                int dist = (cur - prev) / 2;
                int candidate = prev + dist;
                if (dist > bestDist) {
                    bestDist = dist;
                    bestSeat = candidate;
                }
            }
            prev = cur;
        }

        int last = *occupied.rbegin();
        int lastDist = n - 1 - last;
        if (lastDist > bestDist) {
            bestDist = lastDist;
            bestSeat = n - 1;
        }

        occupied.insert(bestSeat);
        return bestSeat;
    }

    void leave(int p) {
        occupied.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
