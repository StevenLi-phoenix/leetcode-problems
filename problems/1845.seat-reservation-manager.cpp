// @leetcode id=1845 questionId=1955 slug=seat-reservation-manager lang=cpp site=leetcode.com title="Seat Reservation Manager"
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> freed;
    int next = 1;

public:
    SeatManager(int n) {
    }

    int reserve() {
        if (!freed.empty()) {
            int seat = freed.top();
            freed.pop();
            return seat;
        }
        return next++;
    }

    void unreserve(int seatNumber) {
        freed.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
