// @leetcode id=146 questionId=146 slug=lru-cache lang=cpp site=leetcode.com title="LRU Cache"
class LRUCache {
public:
    int capacity;
    list<pair<int, int>> items; // front = most recent, back = least recent
    unordered_map<int, list<pair<int, int>>::iterator> pos;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        items.splice(items.begin(), items, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            items.splice(items.begin(), items, it->second);
            return;
        }
        if ((int)items.size() == capacity) {
            pos.erase(items.back().first);
            items.pop_back();
        }
        items.push_front({key, value});
        pos[key] = items.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
