// @leetcode id=677 questionId=677 slug=map-sum-pairs lang=cpp site=leetcode.com title="Map Sum Pairs"
class MapSum {
public:
    MapSum() {
    }

    void insert(string key, int val) {
        vals[key] = val;
    }

    int sum(string prefix) {
        int total = 0;
        for (auto& [key, val] : vals) {
            if (key.size() >= prefix.size() && key.compare(0, prefix.size(), prefix) == 0) {
                total += val;
            }
        }
        return total;
    }

private:
    unordered_map<string, int> vals;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
