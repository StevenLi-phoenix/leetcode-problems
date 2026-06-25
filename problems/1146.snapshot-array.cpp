// @leetcode id=1146 questionId=1249 slug=snapshot-array lang=cpp site=leetcode.com title="Snapshot Array"
class SnapshotArray {
    int snap_id;
    vector<vector<pair<int,int>>> data; // data[index] = list of (snap_id, value)
public:
    SnapshotArray(int length) : snap_id(0), data(length) {
        // Initialize each index with snap_id=0, value=0
        for (int i = 0; i < length; i++) {
            data[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        // If the last entry has the current snap_id, update it
        if (data[index].back().first == snap_id) {
            data[index].back().second = val;
        } else {
            data[index].push_back({snap_id, val});
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        // Binary search for the largest snap_id <= given snap_id
        auto& v = data[index];
        int lo = 0, hi = (int)v.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (v[mid].first <= snap_id) lo = mid;
            else hi = mid - 1;
        }
        return v[lo].second;
    }
};
