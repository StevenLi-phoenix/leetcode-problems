// @leetcode id=3885 questionId=4267 slug=design-event-manager lang=cpp site=leetcode.com title="Design Event Manager"
class EventManager {
private:
    map<int, int> eventPriority;
    priority_queue<pair<int, int>> pq;

public:
    EventManager(vector<vector<int>>& events) {
        for (auto& event : events) {
            int eventId = event[0];
            int priority = event[1];
            eventPriority[eventId] = priority;
            pq.push({priority, -eventId});
        }
    }

    void updatePriority(int eventId, int newPriority) {
        eventPriority[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }

    int pollHighest() {
        while (!pq.empty()) {
            auto [priority, negId] = pq.top();
            pq.pop();
            int eventId = -negId;

            if (eventPriority.count(eventId) && eventPriority[eventId] == priority) {
                eventPriority.erase(eventId);
                return eventId;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
