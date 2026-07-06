// @leetcode id=853 questionId=883 slug=car-fleet lang=cpp site=leetcode.com title="Car Fleet"
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return position[a] > position[b]; });

        int fleets = 0;
        double lastArrival = -1;

        for (int i : idx) {
            double arrival = (double)(target - position[i]) / speed[i];
            if (arrival > lastArrival) {
                ++fleets;
                lastArrival = arrival;
            }
        }
        return fleets;
    }
};
