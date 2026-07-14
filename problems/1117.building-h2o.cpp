// @leetcode id=1117 questionId=1186 slug=building-h2o lang=cpp site=leetcode.com title="Building H2O"
class H2O {
public:
    mutex mtx;
    condition_variable cv;
    int h = 0, o = 0;

    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return h < 2; });
        h++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (h == 2 && o == 1) { h = 0; o = 0; }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return o < 1; });
        o++;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if (h == 2 && o == 1) { h = 0; o = 0; }
        cv.notify_all();
    }
};
