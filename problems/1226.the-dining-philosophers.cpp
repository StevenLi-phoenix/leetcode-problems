// @leetcode id=1226 questionId=1340 slug=the-dining-philosophers lang=cpp site=leetcode.com title="The Dining Philosophers"
class DiningPhilosophers {
public:
    mutex forks[5];
    
    DiningPhilosophers() {
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        // Always pick the lower-numbered fork first to avoid deadlock
        if (left < right) {
            forks[left].lock();
            forks[right].lock();
            pickLeftFork();
            pickRightFork();
        } else {
            forks[right].lock();
            forks[left].lock();
            pickRightFork();
            pickLeftFork();
        }
        
        eat();
        
        putLeftFork();
        putRightFork();
        forks[left].unlock();
        forks[right].unlock();
    }
};
