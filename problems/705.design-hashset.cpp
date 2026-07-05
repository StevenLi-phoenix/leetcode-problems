// @leetcode id=705 questionId=816 slug=design-hashset lang=cpp site=leetcode.com title="Design HashSet"
class MyHashSet {
public:
    MyHashSet() : buckets(1000) {}

    void add(int key) {
        auto& bucket = buckets[key % 1000];
        for (int v : bucket) if (v == key) return;
        bucket.push_back(key);
    }

    void remove(int key) {
        auto& bucket = buckets[key % 1000];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) { bucket.erase(it); return; }
        }
    }

    bool contains(int key) {
        auto& bucket = buckets[key % 1000];
        for (int v : bucket) if (v == key) return true;
        return false;
    }

private:
    vector<vector<int>> buckets;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
