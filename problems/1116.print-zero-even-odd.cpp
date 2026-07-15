// @leetcode id=1116 questionId=1216 slug=print-zero-even-odd lang=cpp site=leetcode.com title="Print Zero Even Odd"
class ZeroEvenOdd {
private:
    int n;
    int current = 1;
    int state = 0; // 0 = zero's turn, 1 = odd's turn, 2 = even's turn
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return state == 0; });
            printNumber(0);
            state = (current % 2 == 1) ? 1 : 2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return state == 2; });
            printNumber(current);
            current++;
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return state == 1; });
            printNumber(current);
            current++;
            state = 0;
            cv.notify_all();
        }
    }
};
