// @leetcode id=2336 questionId=2413 slug=smallest-number-in-infinite-set lang=cpp site=leetcode.com title="Smallest Number in Infinite Set"
class SmallestInfiniteSet {
private:
    int next = 1;
    set<int> restored;

public:
    SmallestInfiniteSet() {
    }

    int popSmallest() {
        if (!restored.empty()) {
            int smallest = *restored.begin();
            restored.erase(restored.begin());
            return smallest;
        }
        return next++;
    }

    void addBack(int num) {
        if (num < next) restored.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
