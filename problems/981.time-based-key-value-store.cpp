// @leetcode id=981 questionId=1023 slug=time-based-key-value-store lang=cpp site=leetcode.com title="Time Based Key-Value Store"
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        // Timestamps for a given key are strictly increasing across calls,
        // so this is always appended in sorted order.
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";
        auto& entries = it->second;
        int lo = 0, hi = entries.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (entries[mid].first <= timestamp) lo = mid + 1;
            else hi = mid;
        }
        return lo == 0 ? "" : entries[lo - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
