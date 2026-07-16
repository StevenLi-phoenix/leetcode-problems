// @leetcode id=3508 questionId=3827 slug=implement-router lang=cpp site=leetcode.com title="Implement Router"
class Router {
public:
    int memoryLimit;
    deque<array<int, 3>> packets;
    set<tuple<int, int, int>> seen;
    unordered_map<int, deque<int>> destTimestamps;

    Router(int memoryLimit_) {
        memoryLimit = memoryLimit_;
    }

    void removeFront() {
        auto p = packets.front();
        seen.erase({p[0], p[1], p[2]});
        destTimestamps[p[1]].pop_front();
        packets.pop_front();
    }

    bool addPacket(int source, int destination, int timestamp) {
        auto key = make_tuple(source, destination, timestamp);
        if (seen.count(key)) return false;
        if ((int)packets.size() == memoryLimit) {
            removeFront();
        }
        packets.push_back({source, destination, timestamp});
        seen.insert(key);
        destTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        auto p = packets.front();
        removeFront();
        return {p[0], p[1], p[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& d = destTimestamps[destination];
        auto lo = lower_bound(d.begin(), d.end(), startTime);
        auto hi = upper_bound(d.begin(), d.end(), endTime);
        return (int)(hi - lo);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
