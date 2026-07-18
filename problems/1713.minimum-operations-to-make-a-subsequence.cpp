// @leetcode id=1713 questionId=1832 slug=minimum-operations-to-make-a-subsequence lang=cpp site=leetcode.com title="Minimum Operations to Make a Subsequence"
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> pos;
        for (int i = 0; i < (int)target.size(); i++) pos[target[i]] = i;

        vector<int> seq;
        for (int v : arr) {
            auto it = pos.find(v);
            if (it != pos.end()) seq.push_back(it->second);
        }

        vector<int> tails;
        for (int x : seq) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }

        return target.size() - tails.size();
    }
};
