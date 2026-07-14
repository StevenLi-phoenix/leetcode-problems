// @leetcode id=1115 questionId=1187 slug=print-foobar-alternately lang=cpp site=leetcode.com title="Print FooBar Alternately"
class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooTurn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return fooTurn; });
            printFoo();
            fooTurn = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return !fooTurn; });
            printBar();
            fooTurn = true;
            cv.notify_all();
        }
    }
};
