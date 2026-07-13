// @leetcode id=2391 questionId=2471 slug=minimum-amount-of-time-to-collect-garbage lang=cpp site=leetcode.com title="Minimum Amount of Time to Collect Garbage"
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> prefixTravel(n, 0);
        for (int i = 1; i < n; i++) prefixTravel[i] = prefixTravel[i - 1] + travel[i - 1];

        int total = 0;
        unordered_map<char, int> lastHouse;
        for (int i = 0; i < n; i++) {
            total += garbage[i].size();
            for (char c : garbage[i]) lastHouse[c] = i;
        }

        for (auto& [c, house] : lastHouse) total += prefixTravel[house];
        return total;
    }
};
