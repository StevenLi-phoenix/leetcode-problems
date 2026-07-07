// @leetcode id=1346 questionId=1468 slug=check-if-n-and-its-double-exist lang=cpp site=leetcode.com title="Check If N and Its Double Exist"
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int v : arr) {
            if (seen.count(v * 2) || (v % 2 == 0 && seen.count(v / 2))) {
                return true;
            }
            seen.insert(v);
        }
        return false;
    }
};
