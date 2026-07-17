// @leetcode id=381 questionId=381 slug=insert-delete-getrandom-o1-duplicates-allowed lang=cpp site=leetcode.com title="Insert Delete GetRandom O(1) - Duplicates allowed"
class RandomizedCollection {
public:
    vector<int> values;
    unordered_map<int, unordered_set<int>> indices;

    RandomizedCollection() {}

    bool insert(int val) {
        bool isNew = indices[val].empty();
        indices[val].insert(values.size());
        values.push_back(val);
        return isNew;
    }

    bool remove(int val) {
        if (indices.find(val) == indices.end() || indices[val].empty()) return false;

        int idx = *indices[val].begin();
        indices[val].erase(idx);

        int lastVal = values.back();
        values[idx] = lastVal;

        if (idx != (int)values.size() - 1) {
            indices[lastVal].erase(values.size() - 1);
            indices[lastVal].insert(idx);
        }
        values.pop_back();

        if (indices[val].empty()) indices.erase(val);
        return true;
    }

    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
