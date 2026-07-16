// @leetcode id=1195 questionId=1316 slug=fizz-buzz-multithreaded lang=cpp site=leetcode.com title="Fizz Buzz Multithreaded"
class FizzBuzz {
private:
    int n;
    int cur = 1;
    mutex mtx;
    condition_variable cv;

    bool isFizz(int i) { return i % 3 == 0 && i % 5 != 0; }
    bool isBuzz(int i) { return i % 5 == 0 && i % 3 != 0; }
    bool isFizzBuzz(int i) { return i % 3 == 0 && i % 5 == 0; }
    bool isNumber(int i) { return i % 3 != 0 && i % 5 != 0; }

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(mtx);
        while (cur <= n) {
            cv.wait(lock, [&] { return cur > n || isFizz(cur); });
            if (cur > n) return;
            printFizz();
            cur++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(mtx);
        while (cur <= n) {
            cv.wait(lock, [&] { return cur > n || isBuzz(cur); });
            if (cur > n) return;
            printBuzz();
            cur++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(mtx);
        while (cur <= n) {
            cv.wait(lock, [&] { return cur > n || isFizzBuzz(cur); });
            if (cur > n) return;
            printFizzBuzz();
            cur++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (cur <= n) {
            cv.wait(lock, [&] { return cur > n || isNumber(cur); });
            if (cur > n) return;
            printNumber(cur);
            cur++;
            cv.notify_all();
        }
    }
};
