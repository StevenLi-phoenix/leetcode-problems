// @leetcode id=2951 questionId=3221 slug=find-the-peaks lang=cpp site=leetcode.com title="Find the Peaks"
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> result;
        for (int i = 1; i + 1 < (int)mountain.size(); i++) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
