// @leetcode id=3852 questionId=4231 slug=smallest-pair-with-different-frequencies lang=cpp site=leetcode.com title="Smallest Pair With Different Frequencies"
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> freq;
        for (int x : nums) freq[x]++;

        vector<int> values;
        for (auto& [val, cnt] : freq) values.push_back(val);

        for (int i = 0; i < (int)values.size(); i++) {
            for (int j = i + 1; j < (int)values.size(); j++) {
                if (freq[values[i]] != freq[values[j]]) {
                    return {values[i], values[j]};
                }
            }
        }

        return {-1, -1};
    }
};
