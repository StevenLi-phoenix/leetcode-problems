// @leetcode id=2170 questionId=2289 slug=minimum-operations-to-make-the-array-alternating lang=cpp site=leetcode.com title="Minimum Operations to Make the Array Alternating"
class Solution {
public:
    vector<pair<int, int>> topTwo(unordered_map<int, int>& freq) {
        pair<int, int> first = {-1, 0}, second = {-1, 0};
        for (auto& [val, cnt] : freq) {
            if (cnt > first.second) {
                second = first;
                first = {val, cnt};
            } else if (cnt > second.second) {
                second = {val, cnt};
            }
        }
        return {first, second};
    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> evenFreq, oddFreq;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) evenFreq[nums[i]]++;
            else oddFreq[nums[i]]++;
        }

        auto evenTop = topTwo(evenFreq);
        auto oddTop = topTwo(oddFreq);
        auto [e1v, e1c] = evenTop[0];
        auto [e2v, e2c] = evenTop[1];
        auto [o1v, o1c] = oddTop[0];
        auto [o2v, o2c] = oddTop[1];

        int bestKept;
        if (e1v != o1v) {
            bestKept = e1c + o1c;
        } else {
            bestKept = max(e1c + o2c, e2c + o1c);
        }
        return n - bestKept;
    }
};
