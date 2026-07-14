// @leetcode id=911 questionId=947 slug=online-election lang=cpp site=leetcode.com title="Online Election"
class TopVotedCandidate {
public:
    vector<int> leaders;
    vector<int> times;

    TopVotedCandidate(vector<int>& persons, vector<int>& times_) {
        times = times_;
        unordered_map<int, int> count;
        int currentLeader = -1;
        for (int p : persons) {
            count[p]++;
            if (currentLeader == -1 || count[p] >= count[currentLeader]) {
                currentLeader = p;
            }
            leaders.push_back(currentLeader);
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
