// @leetcode id=3572 questionId=3894 slug=maximize-ysum-by-picking-a-triplet-of-distinct-xvalues lang=cpp site=leetcode.com title="Maximize Y‑Sum by Picking a Triplet of Distinct X‑Values"
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> bestY;
        for (size_t i = 0; i < x.size(); i++) {
            auto it = bestY.find(x[i]);
            if (it == bestY.end() || y[i] > it->second) {
                bestY[x[i]] = y[i];
            }
        }

        if (bestY.size() < 3) return -1;

        vector<int> vals;
        for (auto& [k, v] : bestY) vals.push_back(v);
        sort(vals.begin(), vals.end(), greater<int>());

        return vals[0] + vals[1] + vals[2];
    }
};
