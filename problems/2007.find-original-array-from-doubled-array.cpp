// @leetcode id=2007 questionId=2117 slug=find-original-array-from-doubled-array lang=cpp site=leetcode.com title="Find Original Array From Doubled Array"
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {};

        map<int, int> count;
        for (int x : changed) count[x]++;

        vector<int> result;

        if (count.count(0)) {
            int zeroCount = count[0];
            if (zeroCount % 2 != 0) return {};
            for (int i = 0; i < zeroCount / 2; i++) result.push_back(0);
            count.erase(0);
        }

        for (auto& [v, cnt] : count) {
            if (cnt <= 0) continue;
            while (count[v] > 0) {
                if (count.find(2 * v) == count.end() || count[2 * v] <= 0) return {};
                count[v]--;
                count[2 * v]--;
                result.push_back(v);
            }
        }

        return result;
    }
};
