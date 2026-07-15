// @leetcode id=2150 questionId=2270 slug=find-all-lonely-numbers-in-the-array lang=cpp site=leetcode.com title="Find All Lonely Numbers in the Array"
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;

        vector<int> result;
        for (int x : nums) {
            if (count[x] == 1 && count.find(x - 1) == count.end() && count.find(x + 1) == count.end()) {
                result.push_back(x);
            }
        }
        return result;
    }
};
