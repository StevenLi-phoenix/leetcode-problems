// @leetcode id=846 questionId=876 slug=hand-of-straights lang=cpp site=leetcode.com title="Hand of Straights"
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for (int v : hand) count[v]++;

        while (!count.empty()) {
            int start = count.begin()->first;
            int need = count.begin()->second;
            for (int v = start; v < start + groupSize; v++) {
                auto it = count.find(v);
                if (it == count.end() || it->second < need) return false;
                it->second -= need;
                if (it->second == 0) count.erase(it);
            }
        }
        return true;
    }
};
