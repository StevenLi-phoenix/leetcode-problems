// @leetcode id=460 questionId=460 slug=lfu-cache lang=cpp site=leetcode.com title="LFU Cache"
class LFUCache {
public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        auto it = nodes.find(key);
        if (it == nodes.end()) return -1;
        touch(key);
        return it->second.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = nodes.find(key);
        if (it != nodes.end()) {
            it->second.value = value;
            touch(key);
            return;
        }

        if ((int)nodes.size() >= capacity) {
            auto& lst = freqLists[minFreq];
            int evictKey = lst.back();
            lst.pop_back();
            iterators.erase(evictKey);
            nodes.erase(evictKey);
        }

        nodes[key] = {value, 1};
        freqLists[1].push_front(key);
        iterators[key] = freqLists[1].begin();
        minFreq = 1;
    }

private:
    struct Node {
        int value;
        int freq;
    };

    int capacity;
    int minFreq;
    unordered_map<int, Node> nodes;
    unordered_map<int, list<int>> freqLists;
    unordered_map<int, list<int>::iterator> iterators;

    void touch(int key) {
        int freq = nodes[key].freq;
        freqLists[freq].erase(iterators[key]);
        if (freqLists[freq].empty() && minFreq == freq) minFreq++;

        int newFreq = freq + 1;
        nodes[key].freq = newFreq;
        freqLists[newFreq].push_front(key);
        iterators[key] = freqLists[newFreq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
