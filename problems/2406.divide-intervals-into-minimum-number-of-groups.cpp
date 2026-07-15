// @leetcode id=2406 questionId=2488 slug=divide-intervals-into-minimum-number-of-groups lang=cpp site=leetcode.com title="Divide Intervals Into Minimum Number of Groups"
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (auto& iv : intervals) {
            starts.push_back(iv[0]);
            ends.push_back(iv[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int i = 0, j = 0, active = 0, best = 0;
        int n = starts.size();
        while (i < n) {
            if (starts[i] <= ends[j]) {
                active++;
                i++;
                best = max(best, active);
            } else {
                active--;
                j++;
            }
        }
        return best;
    }
};
