// @leetcode id=432 questionId=432 slug=all-oone-data-structure lang=cpp site=leetcode.com title="All O`one Data Structure"
class AllOne {
public:
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> keyToBucket;

    AllOne() {

    }

    void inc(string key) {
        auto it = keyToBucket.find(key);
        if (it == keyToBucket.end()) {
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front(Bucket{1, {}});
            }
            buckets.front().keys.insert(key);
            keyToBucket[key] = buckets.begin();
        } else {
            auto curIt = it->second;
            auto nextIt = next(curIt);
            if (nextIt == buckets.end() || nextIt->count != curIt->count + 1) {
                nextIt = buckets.insert(nextIt, Bucket{curIt->count + 1, {}});
            }
            nextIt->keys.insert(key);
            keyToBucket[key] = nextIt;

            curIt->keys.erase(key);
            if (curIt->keys.empty()) buckets.erase(curIt);
        }
    }

    void dec(string key) {
        auto it = keyToBucket.find(key);
        auto curIt = it->second;
        int cnt = curIt->count;

        if (cnt == 1) {
            keyToBucket.erase(it);
        } else {
            auto prevIt = (curIt == buckets.begin()) ? buckets.end() : prev(curIt);
            if (prevIt == buckets.end() || prevIt->count != cnt - 1) {
                prevIt = buckets.insert(curIt, Bucket{cnt - 1, {}});
            }
            prevIt->keys.insert(key);
            keyToBucket[key] = prevIt;
        }

        curIt->keys.erase(key);
        if (curIt->keys.empty()) buckets.erase(curIt);
    }

    string getMaxKey() {
        if (buckets.empty()) return "";
        return *buckets.back().keys.begin();
    }

    string getMinKey() {
        if (buckets.empty()) return "";
        return *buckets.front().keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
