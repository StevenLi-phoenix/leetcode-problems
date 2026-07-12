// @leetcode id=1640 questionId=1760 slug=check-array-formation-through-concatenation lang=cpp site=leetcode.com title="Check Array Formation Through Concatenation"
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>*> byFirst;
        for (auto& p : pieces) byFirst[p[0]] = &p;

        int i = 0;
        while (i < (int)arr.size()) {
            auto it = byFirst.find(arr[i]);
            if (it == byFirst.end()) return false;
            for (int v : *(it->second)) {
                if (i >= (int)arr.size() || arr[i] != v) return false;
                i++;
            }
        }
        return true;
    }
};
