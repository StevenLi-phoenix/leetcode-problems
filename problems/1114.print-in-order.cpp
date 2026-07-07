// @leetcode id=1114 questionId=1203 slug=print-in-order lang=cpp site=leetcode.com title="Print in Order"
class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int stage = 1;

public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        stage = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return stage == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        stage = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return stage == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
