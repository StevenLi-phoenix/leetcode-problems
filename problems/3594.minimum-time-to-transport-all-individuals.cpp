// @leetcode id=3594 questionId=3896 slug=minimum-time-to-transport-all-individuals lang=cpp site=leetcode.com title="Minimum Time to Transport All Individuals"
class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        int full = 1 << n;
        // state index: mask * 2 * m + boatAtStart(0/1) * m + stage
        int numStates = full * 2 * m;
        vector<double> dist(numStates, -1.0);
        auto stateIdx = [&](int mask, int boatAtStart, int stage) {
            return (mask * 2 + boatAtStart) * m + stage;
        };

        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<>> pq;
        int startState = stateIdx(full - 1, 1, 0);
        dist[startState] = 0.0;
        pq.push({0.0, startState});

        double answer = -1.0;

        while (!pq.empty()) {
            auto [d, st] = pq.top();
            pq.pop();
            if (dist[st] < d - 1e-12) continue;

            int stage = st % m;
            int rem = st / m;
            int boatAtStart = rem % 2;
            int mask = rem / 2;

            if (mask == 0) {
                answer = d;
                break;
            }

            if (boatAtStart == 1) {
                // choose subset of people at start (bits in mask), size 1..k
                for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                    int cnt = __builtin_popcount(sub);
                    if (cnt > k) continue;
                    double maxTime = 0;
                    for (int i = 0; i < n; i++) {
                        if (sub & (1 << i)) maxTime = max(maxTime, (double)time[i]);
                    }
                    double crossTime = maxTime * mul[stage];
                    int newStage = ((int)floor(crossTime) % m + stage) % m;
                    int newMask = mask & ~sub;
                    int newSt = stateIdx(newMask, 0, newStage);
                    double newDist = d + crossTime;
                    if (dist[newSt] < 0 || newDist < dist[newSt] - 1e-12) {
                        dist[newSt] = newDist;
                        pq.push({newDist, newSt});
                    }
                }
            } else {
                // boat at destination, must return exactly one person from destination (bit=0 in mask)
                for (int r = 0; r < n; r++) {
                    if (mask & (1 << r)) continue; // r is at start already, skip
                    double returnTime = time[r] * mul[stage];
                    int newStage = ((int)floor(returnTime) % m + stage) % m;
                    int newMask = mask | (1 << r);
                    int newSt = stateIdx(newMask, 1, newStage);
                    double newDist = d + returnTime;
                    if (dist[newSt] < 0 || newDist < dist[newSt] - 1e-12) {
                        dist[newSt] = newDist;
                        pq.push({newDist, newSt});
                    }
                }
            }
        }

        return answer;
    }
};
