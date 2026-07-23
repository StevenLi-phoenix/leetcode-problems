// @leetcode id=1394 questionId=1510 slug=find-lucky-integer-in-an-array lang=cpp site=leetcode.com title="Find Lucky Integer in an Array"
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;

        int best = -1;
        for (auto& [val, count] : freq) {
            if (val == count) best = max(best, val);
        }
        return best;
    }
};
